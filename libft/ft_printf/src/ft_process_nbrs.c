/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_nbrs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 19:43:34 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/02 19:43:36 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_process_nbrs(va_list *arg, t_struct *print, int *chars_ret)
{
	char		*str;
	intmax_t	nbr;

	str = NULL;
	nbr = va_arg(*arg, intmax_t);
	if (CONV_LET == 'd' || CONV_LET == 'i' || CONV_LET == 'D')
		ft_process_d_i(print, &nbr, str, chars_ret);
	if (CONV_LET == 'o' || CONV_LET == 'O')
		ft_process_oct(print, &nbr, str, chars_ret);
	if (CONV_LET == 'u' || CONV_LET == 'U')
		ft_process_unsigned(print, &nbr, str, chars_ret);
	if (CONV_LET == 'x' || CONV_LET == 'X')
		ft_process_hex(print, &nbr, str, chars_ret);
	if (CONV_LET == 'p')
		ft_process_address(print, str, &nbr, chars_ret);
}
