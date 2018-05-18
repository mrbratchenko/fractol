/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actual_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:02:04 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/02 19:08:39 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		ft_other_conv(t_struct *print, va_list *arg, int *chars_ret)
{
	if (CONV_LET == 'd' || CONV_LET == 'i' || CONV_LET == 'o' ||
		CONV_LET == 'u' || CONV_LET == 'U' || CONV_LET == 'x' ||
		CONV_LET == 'X' || CONV_LET == 'D' || CONV_LET == 'O' ||
		CONV_LET == 'p')
		ft_process_nbrs(arg, print, chars_ret);
	if (CONV_LET == 's' && print->size_mod1 != 'l')
		ft_process_str(arg, print, chars_ret);
	if (CONV_LET == 'S' || (CONV_LET == 's' && SZ_MOD1 == 'l'))
		ft_process_w_str(va_arg(*arg, wchar_t*), chars_ret, print);
	if (CONV_LET == 'c' && SZ_MOD1 != 'l')
		ft_process_char(arg, print, chars_ret);
	if ((CONV_LET == 'C') || (CONV_LET == 'c' && SZ_MOD1 == 'l'))
		ft_process_w_char(print, va_arg(*arg, wchar_t), chars_ret, 0);
	if (CONV_LET == '%')
		ft_process_percent(print, chars_ret);
}

static void		ft_stp_struct(t_struct *print)
{
	print->invalid_spec = '\0';
	print->fl1 = '\0';
	print->fl2 = '\0';
	print->fl3 = '\0';
	print->fl4 = '\0';
	print->min_width = 0;
	print->dot = '\0';
	print->prec = 0;
	print->size_mod1 = '\0';
	print->size_mod2 = '\0';
	print->conv_let = '\0';
}

char			*ft_actual_printf(char *format, va_list *arg, int *chars_ret)
{
	char		*start;
	t_struct	*print;

	if (!(print = (t_struct *)malloc(sizeof(t_struct))))
	{
		free(print);
		return (NULL);
	}
	ft_stp_struct(print);
	start = format;
	ft_get_specs(&format, print);
	if (print->invalid_spec)
	{
		free(print);
		return (start + ft_process_invalid(print, INVLD_SP, chars_ret));
	}
	if (!CONV_LET)
	{
		free(print);
		return (start - 1);
	}
	ft_other_conv(print, arg, chars_ret);
	free(print);
	return ((char *)format);
}
