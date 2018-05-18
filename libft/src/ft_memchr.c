/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:33:22 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/04 17:33:24 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*copy;

	i = 0;
	copy = s;
	while (n > i)
	{
		if (copy[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
