/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 19:08:51 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/02 19:08:53 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_get_wid_prec(int *curr, char **s)
{
	int len;
	int copy;

	len = 0;
	*curr = ft_atoi(*s);
	copy = *curr;
	while (copy != 0)
	{
		copy = copy / 10;
		len++;
	}
	*s += len;
}

static int	ft_is_val_alpha(char *s)
{
	if (*s != 'h' && *s != 'l' && *s != 'j' && *s != 'z' && *s != 's' &&
		*s != '%' && *s != 'S' && *s != 'p' && *s != 'd' && *s != 'D' &&
		*s != 'i' && *s != 'o' && *s != 'O' && *s != 'u' && *s != 'U' &&
		*s != 'x' && *s != 'X' && *s != 'c' && *s != 'C' && ft_isalpha(*s))
		return (1);
	return (0);
}

static void	ft_find_specs(char *s, t_struct *print)
{
	while (*s)
	{
		if (!FLAG1 && VLD_FLS && *(s - 1) != '.' && *s != *(s + 1))
			FLAG1 = *s++;
		if (!FLAG2 && VLD_FLS && *(s - 1) != '.' && *s != *(s - 1))
			FLAG2 = *s++;
		if (!FLAG3 && VLD_FLS && *(s - 1) != '.')
			FLAG3 = *s++;
		if (!FLAG4 && VLD_FLS && *(s - 1) != '.')
			FLAG4 = *s++;
		if (ft_isdigit(*s) && *(s - 1) != '.')
			ft_get_wid_prec(&print->min_width, &s);
		if (*s == '.')
			print->dot = *s++;
		if (ft_isdigit(*s) && *(s - 1) == '.')
			ft_get_wid_prec(&print->prec, &s);
		if (*s == 'h' || *s == 'l' || *s == 'j' || *s == 'z')
			print->size_mod1 = *s++;
		if (*s == 'h' || *s == 'l')
			print->size_mod2 = *s++;
		if (ft_is_val_alpha(s))
			print->invalid_spec = *s++;
		s++;
	}
}

static void	ft_manage_fl(t_struct *print)
{
	if ((FLAG1 == '0') && (FLAG2 == '-' || FLAG3 == '-' || FLAG4 == '-'))
		FLAG1 = '\0';
	if ((FLAG2 == '0') && (FLAG1 == '-' || FLAG3 == '-' || FLAG4 == '-'))
		FLAG2 = '\0';
	if ((FLAG3 == '0') && (FLAG1 == '-' || FLAG2 == '-' || FLAG4 == '-'))
		FLAG3 = '\0';
	if ((FLAG4 == '0') && (FLAG1 == '-' || FLAG2 == '-' || FLAG3 == '-'))
		FLAG4 = '\0';
	if ((FLAG1 == ' ') && (FLAG2 == '+' || FLAG3 == '+' || FLAG4 == '+'))
		FLAG1 = '\0';
	if ((FLAG2 == ' ') && (FLAG1 == '+' || FLAG3 == '+' || FLAG4 == '+'))
		FLAG2 = '\0';
	if ((FLAG3 == ' ') && (FLAG1 == '+' || FLAG2 == '+' || FLAG4 == '+'))
		FLAG3 = '\0';
	if ((FLAG4 == ' ') && (FLAG1 == '+' || FLAG2 == '+' || FLAG3 == '+'))
		FLAG4 = '\0';
}

void		ft_get_specs(char **format, t_struct *print)
{
	char	*s;
	char	*free_str;
	char	*start;
	int		i;

	start = *format;
	i = 0;
	while (**format && ++i)
	{
		if (**format == 's' || **format == 'S' || **format == 'p' ||
			**format == 'd' || **format == 'D' || **format == 'i' ||
			**format == 'o' || **format == 'O' || **format == 'u' ||
			**format == 'U' || **format == 'x' || **format == 'X' ||
			**format == 'c' || **format == 'C' || **format == '%')
		{
			print->conv_let = **format;
			break ;
		}
		(*format)++;
	}
	s = ft_strsub(start, 0, i);
	free_str = s;
	ft_find_specs(s, print);
	ft_manage_fl(print);
	free(free_str);
}
