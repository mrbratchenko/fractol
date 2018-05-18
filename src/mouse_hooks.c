/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 20:51:39 by sbratche          #+#    #+#             */
/*   Updated: 2018/05/13 20:51:41 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

int				ft_mouse(int x, int y, t_ptrs *ptrs)
{
	if (ptrs->fractol == 'j')
	{
		if (x > 500 && y > 500)
			ptrs->c_i += 0.01;
		else if (x > 500 && y < 500)
			ptrs->c_r += 0.01;
		else if (x < 500 && y > 500)
			ptrs->c_i -= 0.01;
		else if (x < 500 && y < 500)
			ptrs->c_r -= 0.01;
		ft_put_image(ptrs);
	}
	return (0);
}

int				ft_wheel(int button, int x, int y, t_ptrs *ptrs)
{
	if (x && y)
	{
		button == 5 ? ptrs->zoom *= 1.05 : 0;
		button == 4 ? ptrs->zoom /= 1.05 : 0;
		ft_put_image(ptrs);
	}
	return (0);
}

int				ft_mouse_close(void)
{
	exit(0);
}
