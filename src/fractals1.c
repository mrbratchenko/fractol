/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 19:26:15 by sbratche          #+#    #+#             */
/*   Updated: 2018/05/14 19:26:17 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void			ft_draw_buffalo(t_ptrs *ptrs, double y_beg, double y_end,
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
				x_temp = fabs(x * x - y * y - x + thr->c_r);
				y = fabs(2 * x * y - y + thr->c_i);
				x = x_temp;
			}
			thr->z = x * x + y * y;
			ft_map_pixel(ptrs, thr->x, y_beg, thr);
			thr->x++;
		}
		y_beg++;
	}
}

void			ft_draw_drop(t_ptrs *ptrs, double y_beg, double y_end,
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
			thr->c_r = (y_beg - WIN_H / 2) * -4 / WIN_H * ptrs->zoom - ptrs->my;
			thr->c_i = (thr->x - WIN_W / 2) * 4 / WIN_W * ptrs->zoom + ptrs->mx;
			ft_thread_init(thr);
			ft_set_to_zero(&x, &y, &thr->iter);
			while (x * x + y * y < ptrs->escape && ++thr->iter < ptrs->max_i)
			{
				x_temp = x * x - y * y + thr->c_r / (thr->c_r2 + thr->c_i2);
				y = 2 * x * y - thr->c_i / (thr->c_r2 + thr->c_i2);
				x = x_temp;
			}
			thr->z = x * x + y * y;
			ft_map_pixel(ptrs, thr->x, y_beg, thr);
			thr->x++;
		}
		y_beg++;
	}
}

void			ft_draw_tricorn(t_ptrs *ptrs, double y_beg, double y_end,
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
				y = -2 * x * y + thr->c_i;
				x = x_temp;
			}
			thr->z = x * x + y * y;
			ft_map_pixel(ptrs, thr->x, y_beg, thr);
			thr->x++;
		}
		y_beg++;
	}
}
