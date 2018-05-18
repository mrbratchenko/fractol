/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:29 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/11 17:01:34 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_to_caps(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
}

static int		ft_count_base(uintmax_t n, int base)
{
	int	len;

	len = 1;
	while (n >= (uintmax_t)base && len++)
		n = n / base;
	return (len);
}

static	char	*ft_convert(uintmax_t n, int i, char *str, int base)
{
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		if (base <= 10)
			str[i] = (n % base) + '0';
		else
		{
			if (n % base < 10)
				str[i] = (n % base) + '0';
			else
				str[i] = (n % base) - 10 + 'a';
		}
		n = n / base;
		i--;
	}
	return (str);
}

char			*ft_itoa_base_unsigned(uintmax_t n, int base, int is_cap)
{
	char	*str;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	i = ft_count_base(n, base);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
	{
		free(str);
		return (NULL);
	}
	if (str != NULL)
	{
		str = ft_convert(n, i, str, base);
		if (is_cap)
			ft_to_caps(str);
	}
	return (str);
}
