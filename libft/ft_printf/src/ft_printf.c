/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 12:27:50 by sbratche          #+#    #+#             */
/*   Updated: 2018/01/27 12:28:02 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_printf(const char *format, ...)
{
	va_list			arg;
	int				chars_ret;

	chars_ret = 0;
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format = ft_actual_printf((char *)format + 1, &arg, &chars_ret);
			if (!format)
				return (0);
		}
		else
		{
			ft_putchar(*format);
			chars_ret++;
		}
		format++;
	}
	va_end(arg);
	return (chars_ret);
}
