/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:56:37 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/24 16:56:39 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

static void		*ft_assign_thread(void *ptr)
{
	double		y_b;
	double		y_e;
	t_ptrs		*ptrs;
	t_thread	*thr;

	thr = (t_thread*)ptr;
	ptrs = thr->ptrs;
	y_b = WIN_H / THREADS * thr->num;
	y_e = y_b + WIN_H / THREADS;
	if (ptrs->fractol == 'm')
		ft_draw_mandelbrot(ptrs, y_b, y_e, thr);
	else if (ptrs->fractol == 'j')
		ft_draw_julia(ptrs, y_b, y_e, thr);
	else if (ptrs->fractol == 'd')
		ft_draw_drop(ptrs, y_b, y_e, thr);
	else if (ptrs->fractol == 't')
		ft_draw_tricorn(ptrs, y_b, y_e, thr);
	else if (ptrs->fractol == 'b')
		ft_draw_buffalo(ptrs, y_b, y_e, thr);
	else if (ptrs->fractol == 's')
		ft_draw_ship(ptrs, y_b, y_e, thr);
	return (NULL);
}

void			ft_put_image(t_ptrs *ptrs)
{
	int			i;
	pthread_t	one_thread[THREADS];
	t_thread	*thr[THREADS];

	ptrs->img_ptr = mlx_new_image(ptrs->mlx_ptr, WIN_H, WIN_W);
	ptrs->image = mlx_get_data_addr(ptrs->img_ptr,
					&ptrs->img_a, &ptrs->img_b, &ptrs->img_c);
	ptrs->img_a /= 8;
	i = 0;
	while (i < THREADS)
	{
		thr[i] = (t_thread *)malloc(sizeof(t_thread));
		thr[i]->ptrs = ptrs;
		thr[i]->num = i;
		pthread_create(&one_thread[i], NULL, &ft_assign_thread, (void*)thr[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(one_thread[i++], NULL);
	i = 0;
	while (i < THREADS)
		free(thr[i++]);
	mlx_put_image_to_window(ptrs->mlx_ptr, ptrs->win_ptr, ptrs->img_ptr, 0, 0);
	ft_strings(ptrs);
}

static void		ft_keys3(t_ptrs *ptrs)
{
	if (ptrs->fractol == 'j')
	{
		ptrs->c_r = -0.6;
		ptrs->c_i = 0.45;
	}
	else if (ptrs->fractol == 's')
	{
		ptrs->zoom = 0.038047;
		ptrs->mx = -1.733187;
		ptrs->my = -0.026327;
	}
	else if (ptrs->fractol == 'd')
		ptrs->zoom = 1.979932;
}

static void		ft_keys2(int key, t_ptrs *ptrs)
{
	key == 119 ? ptrs->phase -= 0.1 : 0;
	key == 116 ? ptrs->freq += 0.1 : 0;
	key == 121 ? ptrs->freq -= 0.1 : 0;
	if (key == 36 || key == 46 || key == 38 ||
		key == 1 || key == 17 || key == 2 || key == 11)
	{
		ptrs->mx = 0.0;
		ptrs->my = 0.0;
		ptrs->zoom = 1.0;
		ptrs->freq = 0.0;
		ptrs->phase = 0.0;
		if (ptrs->fractol == 'm')
			ptrs->fractol = 'j';
		else if (ptrs->fractol == 'j')
			ptrs->fractol = 's';
		else if (ptrs->fractol == 's')
			ptrs->fractol = 't';
		else if (ptrs->fractol == 't')
			ptrs->fractol = 'd';
		else if (ptrs->fractol == 'd')
			ptrs->fractol = 'b';
		else if (ptrs->fractol == 'b')
			ptrs->fractol = 'm';
		ft_keys3(ptrs);
	}
}

int				ft_keys(int key, t_ptrs *ptrs)
{
	if (key == 53)
	{
		mlx_destroy_window(ptrs->mlx_ptr, ptrs->win_ptr);
		exit(0);
	}
	key == 46 ? ptrs->fractol = 'b' : 0;
	key == 38 ? ptrs->fractol = 'm' : 0;
	key == 1 ? ptrs->fractol = 'j' : 0;
	key == 17 ? ptrs->fractol = 's' : 0;
	key == 2 ? ptrs->fractol = 't' : 0;
	key == 11 ? ptrs->fractol = 'd' : 0;
	key == 126 ? ptrs->my -= 0.1 * ptrs->zoom : 0;
	key == 125 ? ptrs->my += 0.1 * ptrs->zoom : 0;
	key == 124 ? ptrs->mx += 0.1 * ptrs->zoom : 0;
	key == 123 ? ptrs->mx -= 0.1 * ptrs->zoom : 0;
	key == 124 ? ptrs->mx += 0.1 * ptrs->zoom : 0;
	key == 123 ? ptrs->mx -= 0.1 * ptrs->zoom : 0;
	key == 69 ? ptrs->max_i += 1 : 0;
	key == 78 ? ptrs->max_i -= 1 : 0;
	key == 27 ? ptrs->escape -= 1 : 0;
	key == 24 ? ptrs->escape += 1 : 0;
	key == 115 ? ptrs->phase += 0.1 : 0;
	ft_keys2(key, ptrs);
	ft_put_image(ptrs);
	return (0);
}
