/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:11:36 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/10 20:11:38 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *str, char c)
{
	int		w;
	int		i;

	i = 0;
	w = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			w++;
		i++;
	}
	if (str[0] != '\0')
		w++;
	return (w);
}

static char	*ft_each_word(char const *str, char c, int *i)
{
	char	*word;
	int		k;

	if (!(word = (char *)malloc(sizeof(char) * ft_strlen(str))))
	{
		free(word);
		return (NULL);
	}
	k = 0;
	while (str[*i] != c && str[*i] != '\0')
	{
		word[k] = str[*i];
		k++;
		*i = *i + 1;
	}
	word[k] = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		w;
	char	**fresh;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	w = ft_word_count(s, c);
	if (!(fresh = (char **)malloc(sizeof(char *) * (w))))
		free(fresh);
	if (fresh == NULL)
		return (NULL);
	while (s[i] == c && s[i] != '\0')
		i++;
	while (j < w && s[i] != '\0')
	{
		fresh[j] = ft_each_word(s, c, &i);
		while (s[i] == c && s[i] != '\0')
			i++;
		j++;
	}
	fresh[j] = NULL;
	return (fresh);
}
