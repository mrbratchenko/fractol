/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_invalid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 20:53:05 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/01 20:53:08 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_len_str(t_struct *print, int *len)
{
	if (FLAG1)
		(*len)++;
	if (FLAG2)
		(*len)++;
	if (FLAG3)
		(*len)++;
	if (FLAG4)
		(*len)++;
	if (print->min_width)
		(*len) += ft_strlen(ft_itoa_base_signed(MIN_WID));
	if (print->prec)
		(*len) += ft_strlen(ft_itoa_base_signed(PREC));
	if (print->size_mod1)
		(*len)++;
	if (print->size_mod2)
		(*len)++;
}

static void	ft_if_min_wid(t_struct *print, char invalid, int *len,
															int *chars_ret)
{
	ft_len_str(print, len);
	if (ZERO_FL)
	{
		while (MIN_WID-- && MIN_WID >= 1)
			ft_print_char('0', chars_ret);
		ft_print_char(invalid, chars_ret);
	}
	else if (MINUS_FL)
	{
		ft_print_char(invalid, chars_ret);
		while (MIN_WID-- && MIN_WID >= 1)
			ft_print_char(' ', chars_ret);
	}
	else
	{
		while (MIN_WID-- && MIN_WID >= 1)
			ft_print_char(' ', chars_ret);
		ft_print_char(invalid, chars_ret);
	}
}

int			ft_process_invalid(t_struct *print, char invalid, int *chars_ret)
{
	int len;

	len = 0;
	if (SPACE_FL)
		len++;
	if (print->dot)
		len++;
	if (MIN_WID > 1)
		ft_if_min_wid(print, invalid, &len, chars_ret);
	else
		ft_print_char(invalid, chars_ret);
	return (len);
}
