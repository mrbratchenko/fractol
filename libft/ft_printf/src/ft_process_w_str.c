/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_w_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 20:29:27 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/01 20:29:40 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_if_min_wid(t_struct *print, wchar_t *copy, int *chars_ret,
																wchar_t *value)
{
	int len;
	int i;

	i = 0;
	while (*copy)
	{
		i += ft_calc_w_len(*copy);
		copy++;
	}
	len = ft_calc_w_len(*value);
	if (MIN_WID < PREC)
		MIN_WID = MIN_WID - len;
	if (ZERO_FL)
	{
		MIN_WID = MIN_WID - i;
		while (MIN_WID-- && MIN_WID >= 0)
			ft_print_char('0', chars_ret);
	}
	if (!PREC && !MINUS_FL)
		while (MIN_WID-- && MIN_WID >= i)
			ft_print_char(' ', chars_ret);
	if (PREC && !MINUS_FL)
		while (MIN_WID-- && MIN_WID >= len)
			ft_print_char(' ', chars_ret);
}

static void	ft_if_prec(t_struct *print, int *chars_ret, wchar_t *value)
{
	int len;

	if (PREC)
	{
		len = 0;
		while (PREC >= len)
		{
			len += ft_calc_w_len(*value);
			if (PREC < len)
				break ;
			ft_process_w_char(print, *value, chars_ret, 1);
			value++;
		}
	}
}

static void	ft_other_fl(t_struct *print, wchar_t *copy, int *chars_ret,
																wchar_t *value)
{
	int i;

	i = 0;
	while (*copy)
	{
		i += ft_calc_w_len(*copy);
		copy++;
	}
	while (*value)
	{
		ft_process_w_char(print, *value, chars_ret, 1);
		value++;
	}
	if (!PREC && MINUS_FL)
	{
		while (MIN_WID-- && MIN_WID >= i)
			ft_print_char(' ', chars_ret);
	}
}

void		ft_process_w_str(wchar_t *value, int *chars_ret, t_struct *print)
{
	wchar_t		*copy;

	if (value == NULL)
		value = L"(null)";
	if (!PREC && DOT)
	{
		if (ZERO_FL)
		{
			while (MIN_WID-- && MIN_WID >= 0)
				ft_print_char('0', chars_ret);
			return ;
		}
		while (MIN_WID-- && MIN_WID >= 0)
			ft_print_char(' ', chars_ret);
		return ;
	}
	copy = value;
	if (MIN_WID)
		ft_if_min_wid(print, copy, chars_ret, value);
	if (PREC)
		ft_if_prec(print, chars_ret, value);
	else
		ft_other_fl(print, copy, chars_ret, value);
}
