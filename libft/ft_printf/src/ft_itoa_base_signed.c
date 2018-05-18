/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:01:29 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/11 17:01:34 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int		ft_count(intmax_t n)
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

static	char	*ft_convert(intmax_t n, int i, char *str)
{
	int			flag;

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
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	if (flag == -1)
		str[0] = '-';
	return (str);
}

char			*ft_itoa_base_signed(intmax_t n)
{
	char	*str;
	int		i;

	if (n < -9223372036854775807)
	{
		str = ft_strdup("-9223372036854775808");
		return (str);
	}
	i = ft_count(n);
	if (n == 0)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 10));
	if (str != NULL)
		str = ft_convert(n, i, str);
	return (str);
}
