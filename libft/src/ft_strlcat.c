/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 21:42:04 by sbratche          #+#    #+#             */
/*   Updated: 2017/10/30 21:42:07 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*s1;
	const char	*s2;
	size_t		k;
	size_t		i;
	size_t		j;

	s1 = dst;
	s2 = src;
	k = ft_strlen(src);
	i = ft_strlen(dst);
	j = 0;
	if (i < size)
	{
		while (i < size - 1)
		{
			s1[i] = s2[j];
			i++;
			j++;
		}
		s1[i] = '\0';
		return (k + i - j);
	}
	else
		return (k + size);
}
