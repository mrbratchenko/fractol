/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:14:02 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/08 20:14:04 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*fresh;

	if (s1 != NULL && s2 != NULL)
	{
		i = ft_strlen(s1);
		j = ft_strlen(s2);
		fresh = (char *)malloc(sizeof(char) * (i + j + 1));
		if (fresh != NULL)
		{
			fresh = ft_strcpy(fresh, s1);
			fresh = ft_strcat(fresh, s2);
			return (fresh);
		}
	}
	return (NULL);
}
