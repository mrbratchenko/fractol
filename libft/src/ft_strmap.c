/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:10:32 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/07 20:10:33 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*map;

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
				map[i] = f(s[i]);
				i++;
			}
			map[i] = '\0';
			return (map);
		}
	}
	return (NULL);
}
