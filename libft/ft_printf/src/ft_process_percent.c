/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 20:48:21 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/01 20:48:22 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_process_percent(t_struct *print, int *chars_ret)
{
	if (MINUS_FL)
	{
		ft_print_char('%', chars_ret);
		while (MIN_WID-- && MIN_WID >= 1)
			ft_print_char(' ', chars_ret);
	}
	else if (ZERO_FL)
	{
		while (MIN_WID-- && MIN_WID >= 1)
			ft_print_char('0', chars_ret);
		ft_print_char('%', chars_ret);
	}
	else
	{
		while (MIN_WID-- && MIN_WID >= 1)
			ft_print_char(' ', chars_ret);
		ft_print_char('%', chars_ret);
	}
}
