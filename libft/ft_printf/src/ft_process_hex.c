/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 20:57:55 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/01 20:57:57 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_if_minus_fl(t_struct *print, int len, char *str, int *chars_ret)
{
	if (HASH_FL)
	{
		(CONV_LET == 'X') ? (ft_print_str("0X", chars_ret)) :
							(ft_print_str("0x", chars_ret));
		len += 2;
	}
	while (PREC-- && PREC >= (int)ft_strlen(str) && ++len)
		ft_print_char('0', chars_ret);
	ft_print_str(str, chars_ret);
	while (MIN_WID-- && MIN_WID >= len && MIN_WID >= PREC)
		ft_print_char(' ', chars_ret);
}

static void	ft_if_zero_fl(t_struct *print, int len, char *str, int *chars_ret)
{
	if (HASH_FL)
	{
		(CONV_LET == 'X') ? (ft_print_str("0X", chars_ret)) :
							(ft_print_str("0x", chars_ret));
		len += 2;
	}
	while (MIN_WID-- && MIN_WID >= len && MIN_WID >= PREC)
		ft_print_char('0', chars_ret);
	ft_print_str(str, chars_ret);
}

static void	ft_if_hash_fl(t_struct *print, int len, char *str, int *chars_ret)
{
	if (str[0] != '0' && ft_strcmp(str, "\0") != 0)
	{
		len += 2;
		while (MIN_WID-- && MIN_WID >= len && MIN_WID >= PREC)
			ft_print_char(' ', chars_ret);
		(CONV_LET == 'X') ? (ft_print_str("0X", chars_ret)) :
							(ft_print_str("0x", chars_ret));
	}
	if (PREC)
	{
		while (PREC-- && PREC >= (int)ft_strlen(str))
			ft_print_char('0', chars_ret);
	}
	ft_print_str(str, chars_ret);
}

static void	ft_cast_nbr(t_struct *print, intmax_t *nbr)
{
	if (SZ_MOD1 == 'j' || SZ_MOD1 == 'z')
		*nbr = (uintmax_t)(*nbr);
	else if (SZ_MOD1 == 'h')
	{
		if (SZ_MOD2 == 'h')
			*nbr = (unsigned char)*nbr;
		else
			*nbr = (unsigned short)*nbr;
	}
	else if (SZ_MOD1 == 'l')
	{
		if (SZ_MOD2 == 'l')
			*nbr = (unsigned long long)*nbr;
		else
			*nbr = (unsigned long)*nbr;
	}
	else
		*nbr = (unsigned int)*nbr;
}

void		ft_process_hex(t_struct *print, intmax_t *nbr, char *str,
																int *chars_ret)
{
	char	*free_str;

	ft_cast_nbr(print, nbr);
	str = (CONV_LET == 'X') ? ft_itoa_base_unsigned(*nbr, 16, 1) :
											ft_itoa_base_unsigned(*nbr, 16, 0);
	free_str = str;
	if (str[0] == '0' && DOT)
		str = ft_strnew(0);
	if (MINUS_FL)
		ft_if_minus_fl(print, ft_strlen(str), str, chars_ret);
	else if (ZERO_FL)
		ft_if_zero_fl(print, ft_strlen(str), str, chars_ret);
	else if (HASH_FL)
		ft_if_hash_fl(print, ft_strlen(str), str, chars_ret);
	else
	{
		while (MIN_WID-- && MIN_WID >= (int)ft_strlen(str) && MIN_WID >= PREC)
			ft_print_char(' ', chars_ret);
		if (PREC)
			while (PREC-- && PREC >= (int)ft_strlen(str))
				ft_print_char('0', chars_ret);
		ft_print_str(str, chars_ret);
	}
	free(free_str);
}
