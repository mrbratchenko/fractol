/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:29:50 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/17 20:29:53 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_binary_search(int value, int *values, int n)
{
	int i;

	i = 0;
	if (n <= 0)
		return (1);
	n -= 1;
	while ((n - i) >= 0)
	{
		if (values[(n + i) / 2] == value)
		{
			return (0);
		}
		else if (values[(n + i) / 2] < value)
		{
			i = ((n + i) / 2) + 1;
		}
		else if (value < values[(n + i) / 2])
		{
			n = ((n + i) / 2) - 1;
		}
	}
	return (1);
}
