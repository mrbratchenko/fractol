/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 13:13:50 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/02 19:31:29 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_print_str(char *ret_str, int *chars_ret)
{
	if (ret_str != NULL)
	{
		while (*ret_str)
		{
			ft_putchar(*ret_str);
			ret_str++;
			(*chars_ret)++;
		}
	}
}
