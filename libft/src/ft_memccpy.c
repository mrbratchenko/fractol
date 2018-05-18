/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:51:00 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/01 19:51:03 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*p1;
	const unsigned char	*p2;

	p1 = dst;
	p2 = src;
	while (0 < n)
	{
		if (*p2 == (unsigned char)c)
		{
			*(p1++) = *(p2++);
			return (p1);
		}
		*(p1++) = *(p2++);
		n--;
	}
	return (NULL);
}
