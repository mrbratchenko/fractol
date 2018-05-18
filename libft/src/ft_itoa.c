/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:29 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/11 17:01:34 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static	int		ft_count(long long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	char	*ft_convert(long long n, int i, char *str)
{
	long long	c;
	int			flag;

	c = 10;
	flag = 1;
	str[i] = '\0';
	i--;
	if (n < 0)
	{
		flag = -1;
		n = n * flag;
	}
	while (i >= 0)
	{
		str[i] = n % c / (c / 10) + 48;
		c *= 10;
		i--;
	}
	if (flag == -1)
		str[0] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_count(n);
	if (n == 0)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str != NULL)
	{
		str = ft_convert(n, i, str);
		return (str);
	}
	return (NULL);
}
