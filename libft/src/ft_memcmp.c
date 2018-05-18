/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:57:09 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/04 17:57:11 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *string1;
	const unsigned char *string2;

	if (n == 0)
		return (0);
	string1 = s1;
	string2 = s2;
	while ((*string1 == *string2) && (n > 1))
	{
		string1++;
		string2++;
		n--;
	}
	return (*string1 - *string2);
}
