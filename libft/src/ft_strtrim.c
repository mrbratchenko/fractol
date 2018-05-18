/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:48:19 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/10 19:11:45 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*fresh;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (j <= 0)
	{
		j = 1;
		i = 2;
	}
	fresh = (char*)malloc(sizeof(char) * (j - i + 2));
	if (fresh == NULL)
		return (NULL);
	j = j - i + 1;
	fresh = strncpy(fresh, &s[i], j);
	fresh[j] = '\0';
	return (fresh);
}
