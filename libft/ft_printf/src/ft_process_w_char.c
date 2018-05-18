/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_w_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 19:40:03 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/02 19:40:09 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_if_two_bytes(unsigned int wdchr_as_i, int *chars_ret,
														unsigned char char_bit)
{
	unsigned int	msk;
	unsigned char	byte2;
	unsigned char	byte1;

	msk = 49280;
	byte2 = (wdchr_as_i << 26) >> 26;
	byte1 = ((wdchr_as_i >> 6) << 27) >> 27;
	char_bit = (msk >> 8) | byte1;
	ft_print_char(char_bit, chars_ret);
	char_bit = ((msk << 24) >> 24) | byte2;
	ft_print_char(char_bit, chars_ret);
}

static void	ft_if_three_bytes(unsigned int wdchr_as_i, int *chars_ret,
														unsigned char char_bit)
{
	unsigned int	msk;
	unsigned char	byte3;
	unsigned char	byte2;
	unsigned char	byte1;

	msk = 14712960;
	byte3 = (wdchr_as_i << 26) >> 26;
	byte2 = ((wdchr_as_i >> 6) << 26) >> 26;
	byte1 = ((wdchr_as_i >> 12) << 28) >> 28;
	char_bit = (msk >> 16) | byte1;
	ft_print_char(char_bit, chars_ret);
	char_bit = ((msk << 16) >> 24) | byte2;
	ft_print_char(char_bit, chars_ret);
	char_bit = ((msk << 24) >> 24) | byte3;
	ft_print_char(char_bit, chars_ret);
}

static void	ft_if_four_bytes(unsigned int wdchr_as_i, int *chars_ret,
														unsigned char char_bit)
{
	unsigned int	msk;
	unsigned char	byte4;
	unsigned char	byte3;
	unsigned char	byte2;
	unsigned char	byte1;

	msk = 4034953344;
	byte4 = (wdchr_as_i << 26) >> 26;
	byte3 = ((wdchr_as_i >> 6) << 26) >> 26;
	byte2 = ((wdchr_as_i >> 12) << 26) >> 26;
	byte1 = ((wdchr_as_i >> 18) << 29) >> 29;
	char_bit = (msk >> 24) | byte1;
	ft_print_char(char_bit, chars_ret);
	char_bit = ((msk << 8) >> 24) | byte2;
	ft_print_char(char_bit, chars_ret);
	char_bit = ((msk << 16) >> 24) | byte3;
	ft_print_char(char_bit, chars_ret);
	char_bit = ((msk << 24) >> 24) | byte4;
	ft_print_char(char_bit, chars_ret);
}

static int	ft_manage_wchar_fl(t_struct *print, wchar_t wdchr, int *chars_ret)
{
	int len;

	len = ft_calc_w_len(wdchr);
	MIN_WID = MIN_WID - len;
	len = MIN_WID;
	if (ZERO_FL)
		while (MIN_WID-- && MIN_WID >= 0)
			ft_print_char('0', chars_ret);
	else if (!MINUS_FL)
		while (MIN_WID-- && MIN_WID >= 0)
			ft_print_char(' ', chars_ret);
	return (len);
}

void		ft_process_w_char(t_struct *print, wchar_t wdchr,
												int *chars_ret, int if_wstr)
{
	unsigned int	wdchr_as_i;
	int				bin_len;
	unsigned char	char_bit;
	char			*free_str;
	int				len;

	free_str = ft_itoa_base_unsigned(wdchr, 2, 0);
	bin_len = ft_strlen(free_str);
	free(free_str);
	wdchr_as_i = wdchr;
	char_bit = 0;
	if (MIN_WID && !if_wstr)
		len = ft_manage_wchar_fl(print, wdchr, chars_ret);
	if (bin_len <= 7)
		ft_print_char(wdchr, chars_ret);
	else if (bin_len <= 11)
		ft_if_two_bytes(wdchr_as_i, chars_ret, char_bit);
	else if (bin_len <= 16)
		ft_if_three_bytes(wdchr_as_i, chars_ret, char_bit);
	else
		ft_if_four_bytes(wdchr_as_i, chars_ret, char_bit);
	if (MINUS_FL && MIN_WID && !if_wstr)
		while (len-- && len >= 0)
			ft_print_char(' ', chars_ret);
}
