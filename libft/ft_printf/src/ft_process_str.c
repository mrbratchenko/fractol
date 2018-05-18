/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 20:41:11 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/01 20:41:13 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_if_min_wid(t_struct *print, int len, int *chars_ret, char *str)
{
	if (MINUS_FL)
	{
		ft_print_str(str, chars_ret);
		while (MIN_WID-- && MIN_WID >= len)
			ft_print_char(' ', chars_ret);
	}
	else if (ZERO_FL)
	{
		while (MIN_WID-- && MIN_WID >= len)
			ft_print_char('0', chars_ret);
		ft_print_str(str, chars_ret);
	}
	else
	{
		while (MIN_WID-- && MIN_WID >= len)
			ft_print_char(' ', chars_ret);
		ft_print_str(str, chars_ret);
	}
}

void		ft_process_str(va_list *arg, t_struct *print, int *chars_ret)
{
	char	*str;
	int		len;

	str = va_arg(*arg, char *);
	if (str == NULL && !MIN_WID)
	{
		ft_print_str("(null)", chars_ret);
		return ;
	}
	if (PREC && PREC < (int)ft_strlen(str))
		str = ft_strsub(str, 0, PREC);
	if (PREC == 0 && print->dot)
		str = ft_strnew(0);
	len = ft_strlen(str);
	if (MIN_WID > len)
		ft_if_min_wid(print, len, chars_ret, str);
	else
		ft_print_str(str, chars_ret);
}
