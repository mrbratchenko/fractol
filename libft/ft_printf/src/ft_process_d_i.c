/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:48:41 by sbratche          #+#    #+#             */
/*   Updated: 2018/01/31 20:48:43 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_if_other_fl(t_struct *print, int *chars_ret, char *str)
{
	int len;

	len = ft_strlen(str);
	if (PLUS_FL)
		MIN_WID--;
	if (SPACE_FL && !PREC && !PLUS_FL)
		len++;
	if (SPACE_FL && PREC >= MIN_WID)
		ft_print_char(' ', chars_ret);
	while (MIN_WID-- && MIN_WID >= len && MIN_WID >= PREC)
		ft_print_char(' ', chars_ret);
	if (PLUS_FL)
		ft_print_char('+', chars_ret);
	if (PREC)
		while (PREC-- && PREC >= len)
			ft_print_char('0', chars_ret);
	ft_print_str(str, chars_ret);
}

static void	ft_if_zero_fl_or_neg(t_struct *print, char *s,
													int *chars_ret, int is_neg)
{
	if (ZERO_FL && !PREC)
	{
		(is_neg) ? ft_print_char('-', chars_ret) : 0;
		if ((SPACE_FL) || (!PREC && !is_neg && PLUS_FL))
			MIN_WID--;
		while (MIN_WID-- && MIN_WID >= (int)ft_strlen(s) && MIN_WID >= PREC)
			ft_print_char('0', chars_ret);
	}
	else if (is_neg)
	{
		if (MIN_WID >= PREC && !ZERO_FL)
			while (MIN_WID-- && MIN_WID >= (int)ft_strlen(s) && MIN_WID > PREC)
				ft_print_char(' ', chars_ret);
		PREC++;
		if (ZERO_FL)
			while (MIN_WID-- && MIN_WID >= (int)ft_strlen(s) && MIN_WID >= PREC)
				ft_print_char(' ', chars_ret);
		ft_print_char('-', chars_ret);
		while (MIN_WID-- && MIN_WID >= (int)ft_strlen(s) && MIN_WID >= PREC)
			ft_print_char('0', chars_ret);
		if (PREC)
			while (PREC-- && PREC >= (int)ft_strlen(s))
				ft_print_char('0', chars_ret);
	}
	is_neg ? ft_print_str(s + 1, chars_ret) : ft_print_str(s, chars_ret);
}

static void	ft_if_min_or_hash_fl(t_struct *print, int *chars_ret, char *str,
																	int is_neg)
{
	int len;

	len = ft_strlen(str);
	if (is_neg && ++PREC)
		ft_print_char('-', chars_ret);
	if (HASH_FL && ++len)
		ft_print_char('0', chars_ret);
	if (SPACE_FL && !PREC)
		len++;
	if (SPACE_FL && PREC && ++len)
		ft_print_char(' ', chars_ret);
	if (PLUS_FL && !is_neg && ++len)
		ft_print_char('+', chars_ret);
	while (PREC-- && PREC >= (int)ft_strlen(str) && ++len)
		ft_print_char('0', chars_ret);
	is_neg ? ft_print_str(str + 1, chars_ret) : ft_print_str(str, chars_ret);
	while (MIN_WID-- && MIN_WID >= len && MIN_WID >= PREC)
		ft_print_char(' ', chars_ret);
	if (HASH_FL && str[0] != '0' && ++len)
	{
		while (MIN_WID-- && MIN_WID >= len && MIN_WID >= PREC)
			ft_print_char(' ', chars_ret);
		ft_print_char('0', chars_ret);
	}
}

static void	ft_cast_nbr(t_struct *print, intmax_t *nbr)
{
	if (SZ_MOD1 == 'h')
	{
		if (CONV_LET == 'D')
			*nbr = (int)*nbr;
		else if (SZ_MOD2 == 'h')
			*nbr = (char)*nbr;
		else
			*nbr = (short)*nbr;
	}
	if (SZ_MOD1 == 'l')
	{
		if (SZ_MOD2 == 'l')
			*nbr = (long long)*nbr;
		else
			*nbr = (long)*nbr;
	}
	if (SZ_MOD1 != 'j' && SZ_MOD1 != 'l' && SZ_MOD1 != 'z' && CONV_LET != 'D')
		*nbr = (int)*nbr;
}

void		ft_process_d_i(t_struct *print, intmax_t *nbr,
												char *str, int *chars_ret)
{
	int		is_neg;
	char	*free_str;

	ft_cast_nbr(print, nbr);
	str = ft_itoa_base_signed(*nbr);
	free_str = str;
	is_neg = (str[0] == '-') ? 1 : 0;
	if (str[0] == '0' && DOT)
		str = ft_strnew(0);
	if (!PREC && !is_neg && SPACE_FL && !PLUS_FL)
		ft_print_char(' ', chars_ret);
	if (((!PREC && !MIN_WID) || (ZERO_FL && !DOT)) && !is_neg && PLUS_FL)
		ft_print_char('+', chars_ret);
	if (!MIN_WID && !PREC)
		ft_print_str(str, chars_ret);
	else
	{
		if (MINUS_FL || HASH_FL)
			ft_if_min_or_hash_fl(print, chars_ret, str, is_neg);
		else if ((ZERO_FL && !DOT) || is_neg)
			ft_if_zero_fl_or_neg(print, str, chars_ret, is_neg);
		else
			ft_if_other_fl(print, chars_ret, str);
	}
	free(free_str);
}
