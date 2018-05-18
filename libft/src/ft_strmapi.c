/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:33:55 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/07 20:33:56 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*map;

	i = 0;
	if (s != NULL)
	{
		i = ft_strlen(s);
		map = (char *)malloc(sizeof(char) * (i + 1));
		if (map != NULL)
		{
			i = 0;
			while (s[i] != '\0')
			{
				map[i] = f(i, s[i]);
				i++;
			}
			map[i] = '\0';
			return (map);
		}
	}
	return (NULL);
}
