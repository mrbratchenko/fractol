/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:51:36 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/04 16:17:53 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*p1;
	const unsigned char	*p2;

	p1 = dst;
	p2 = src;
	i = len - 1;
	if (p2 < p1)
	{
		while (len--)
		{
			*(p1 + i) = *(p2 + i);
			i--;
		}
	}
	else
	{
		while (len--)
		{
			*(p1++) = *(p2++);
		}
	}
	return (dst);
}
