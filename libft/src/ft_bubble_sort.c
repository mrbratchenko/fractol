/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 20:22:56 by sbratche          #+#    #+#             */
/*   Updated: 2017/11/17 20:22:57 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_bubble_sort(int *values, int n)
{
	int	i;
	int	temp;

	while (n > 0)
	{
		i = 0;
		while (i < (n - 1))
		{
			if (values[i] > values[i + 1])
			{
				temp = values[i];
				values[i] = values[i + 1];
				values[i + 1] = temp;
			}
			i++;
		}
		n--;
	}
}
