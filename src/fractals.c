/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:28:58 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/10 15:31:58 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void			ft_set_to_zero(double *x, double *y, int *iter)
{
	*x = 0;
	*y = 0;
	*iter = 0;
}

void			ft_draw_ship(t_ptrs *ptrs, double y_beg, double y_end,
															t_thread *thr)
{
	double x;
	double y;
	double x_temp;

	while (y_beg < y_end)
	{
		thr->x = 0;
		thr->c_i = (y_beg - WIN_H / 2) * 4 / WIN_H * ptrs->zoom + ptrs->my;
		while (thr->x < WIN_W)
		{
			thr->c_r = (thr->x - WIN_W / 2) * 4 / WIN_W * ptrs->zoom + ptrs->mx;
			ft_set_to_zero(&x, &y, &thr->iter);
			while (x * x + y * y < ptrs->escape && ++thr->iter < ptrs->max_i)
			{
				x_temp = fabs(x * x - y * y + thr->c_r);
				y = fabs(2 * x * y + thr->c_i);
				x = x_temp;
			}
			thr->z = x * x + y * y;
			ft_map_pixel(ptrs, thr->x, y_beg, thr);
			thr->x++;
		}
		y_beg++;
	}
}

void			ft_draw_julia(t_ptrs *ptrs, double y_beg, double y_end,
																t_thread *thr)
{
	double x;
	double y;
	double x_temp;

	while (y_beg < y_end)
	{
		thr->x = 0;
		while (thr->x < WIN_W)
		{
			x = (thr->x - WIN_W / 2) * 4 / WIN_W * ptrs->zoom + ptrs->mx;
			y = (y_beg - WIN_H / 2) * 4 / WIN_H * ptrs->zoom + ptrs->my;
			thr->iter = 0;
			while (x * x + y * y < ptrs->escape && ++thr->iter < ptrs->max_i)
			{
				x_temp = x * x - y * y;
				y = 2 * x * y + ptrs->c_i;
				x = x_temp + ptrs->c_r;
			}
			thr->z = x * x + y * y;
			ft_map_pixel(ptrs, thr->x, y_beg, thr);
			thr->x++;
		}
		y_beg++;
	}
}

void			ft_draw_mandelbrot(t_ptrs *ptrs, double y_beg, double y_end,
																t_thread *thr)
{
	double x;
	double y;
	double x_temp;

	while (y_beg < y_end)
	{
		thr->x = 0;
		thr->c_i = (y_beg - WIN_H / 2) * 4 / WIN_H * ptrs->zoom + ptrs->my;
		while (thr->x < WIN_W)
		{
			thr->c_r = (thr->x - WIN_W / 2) * 4 / WIN_W * ptrs->zoom + ptrs->mx;
			ft_set_to_zero(&x, &y, &thr->iter);
			while (x * x + y * y < ptrs->escape && ++thr->iter < ptrs->max_i)
			{
				x_temp = x * x - y * y + thr->c_r;
				y = 2 * x * y + thr->c_i;
				x = x_temp;
			}
			thr->z = x * x + y * y;
			ft_map_pixel(ptrs, thr->x, y_beg, thr);
			thr->x++;
		}
		y_beg++;
	}
}
