/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_address.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:32:59 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/01 21:33:02 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_precision(t_struct *print, int *chars_ret, char *str)
{
	if (MIN_WID || ft_strcmp(str, "0x0") == 0)
	{
		ft_print_str("0x", chars_ret);
		while (PREC-- && PREC >= (int)ft_strlen(str) - 2)
			ft_print_char('0', chars_ret);
		ft_print_str(str + 2, chars_ret);
	}
	else
	{
		while (PREC-- && PREC > MIN_WID)
			ft_print_char('0', chars_ret);
		ft_print_str("0x", chars_ret);
		ft_print_str(str + 2, chars_ret);
	}
}

static void	ft_minus_zero_fl(t_struct *print, int len, int *chars_ret,
																	char *str)
{
	if (MINUS_FL)
	{
		ft_print_str(str, chars_ret);
		while (MIN_WID-- && MIN_WID >= len)
			ft_print_char(' ', chars_ret);
	}
	else if (ZERO_FL)
	{
		ft_print_str(str, chars_ret);
		while (MIN_WID-- && MIN_WID >= len)
			ft_print_char('0', chars_ret);
	}
}

void		ft_process_address(t_struct *print, char *str, intmax_t *nbr,
																int *chars_ret)
{
	int		len;
	char	*free_str;

	free_str = ft_itoa_base_unsigned(*nbr, 16, 0);
	str = ft_strjoin("0x", free_str);
	free(free_str);
	free_str = str;
	if (print->dot && !print->prec)
		str = "0x";
	len = ft_strlen(str);
	if (MINUS_FL || ZERO_FL)
		ft_minus_zero_fl(print, len, chars_ret, str);
	else if (PREC > MIN_WID)
		ft_precision(print, chars_ret, str);
	else
	{
		while (MIN_WID-- && MIN_WID >= len && MIN_WID >= PREC)
			ft_print_char(' ', chars_ret);
		ft_print_str(str, chars_ret);
	}
	free(free_str);
}
