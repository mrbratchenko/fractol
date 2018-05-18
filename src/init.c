/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 20:59:56 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/19 21:00:19 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void			ft_ptrs_init(t_ptrs *ptrs)
{
	ptrs->mlx_ptr = mlx_init();
	ptrs->win_ptr = mlx_new_window(ptrs->mlx_ptr, WIN_H, WIN_W, "fractal");
	ptrs->img_ptr = mlx_new_image(ptrs->mlx_ptr, WIN_H, WIN_W);
	ptrs->image = mlx_get_data_addr(ptrs->img_ptr,
				&ptrs->img_a, &ptrs->img_b, &ptrs->img_c);
	ptrs->img_a = 0;
	ptrs->img_b = 0;
	ptrs->img_c = 0;
	ptrs->color = 0;
	ptrs->fractol = '\0';
	ptrs->c_r = 0;
	ptrs->c_i = 0;
	ptrs->mx = 0.0;
	ptrs->my = 0.0;
	ptrs->zoom = 1.0;
	ptrs->max_i = 100;
	ptrs->iter = 0;
	ptrs->x = 0;
	ptrs->y = 0;
	ptrs->i = 0;
	ptrs->z = 0;
	ptrs->norm = 0;
	ptrs->phase = 0;
	ptrs->freq = 0;
	ptrs->escape = 10;
}

void			ft_thread_init(t_thread *thr)
{
	thr->c_r2 = thr->c_r * thr->c_r;
	thr->c_i2 = thr->c_i * thr->c_i;
}
