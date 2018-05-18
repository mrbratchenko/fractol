/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:53:41 by sbratche          #+#    #+#             */
/*   Updated: 2017/10/31 18:53:44 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					i;
	unsigned long		n;
	int					flag;

	i = 0;
	n = 0;
	flag = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		flag = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		n = n * 10 + str[i] - 48;
		if (n >= 9223372036854775807 && flag == 1)
			return (-1);
		else if (n > 9223372036854775807 && flag == -1)
			return (0);
		i++;
	}
	return ((int)(flag * n));
}
