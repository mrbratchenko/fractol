/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 21:26:11 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/01 21:26:13 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_if_null_char(t_struct *print, int *chars_ret)
{
	if (MIN_WID)
	{
		if (ZERO_FL)
		{
			while (MIN_WID-- && MIN_WID >= 1)
				ft_print_char('0', chars_ret);
		}
		else
		{
			while (MIN_WID-- && MIN_WID >= 1)
				ft_print_char(' ', chars_ret);
		}
	}
	ft_print_char('\0', chars_ret);
}

static void	ft_if_min_wid(t_struct *print, char ret_chr, int *chars_ret)
{
	if (ZERO_FL)
	{
		ft_print_char(ret_chr, chars_ret);
		while (MIN_WID-- && MIN_WID >= 1)
			ft_print_char('0', chars_ret);
	}
	else if (MINUS_FL)
	{
		ft_print_char(ret_chr, chars_ret);
		while (MIN_WID-- && MIN_WID >= 1)
			ft_print_char(' ', chars_ret);
	}
	else
	{
		while (MIN_WID-- && MIN_WID >= 1)
			ft_print_char(' ', chars_ret);
		ft_print_char(ret_chr, chars_ret);
	}
}

void		ft_process_char(va_list *arg, t_struct *print, int *chars_ret)
{
	char ret_chr;

	ret_chr = va_arg(*arg, int);
	if (ret_chr == '\0')
	{
		ft_if_null_char(print, chars_ret);
		return ;
	}
	if (MIN_WID > 1)
		ft_if_min_wid(print, ret_chr, chars_ret);
	else
		ft_print_char(ret_chr, chars_ret);
}
