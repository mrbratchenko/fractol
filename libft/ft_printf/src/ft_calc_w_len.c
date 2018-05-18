/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_w_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 18:41:50 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/04 18:41:52 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_calc_w_len(wchar_t value)
{
	int		i;
	int		size;
	char	*free_str;

	if (value == L'\0')
		return (0);
	free_str = ft_itoa_base_unsigned(value, 2, 0);
	size = ft_strlen(free_str);
	if (size <= 7)
		i = 1;
	else if (size <= 11)
		i = 2;
	else if (size <= 16)
		i = 3;
	else
		i = 4;
	free(free_str);
	return (i);
}
