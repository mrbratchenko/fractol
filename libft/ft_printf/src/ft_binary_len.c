/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 18:41:59 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/04 18:42:00 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_binary_len(int wdchr)
{
	int		len;
	char	*free_str;

	free_str = ft_itoa_base_unsigned(wdchr, 2, 0);
	len = ft_strlen(free_str);
	free(free_str);
	return (len);
}
