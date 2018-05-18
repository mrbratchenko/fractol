/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 21:02:06 by sbratche          #+#    #+#             */
/*   Updated: 2018/05/13 21:02:08 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

void			ft_map_pixel(t_ptrs *ptrs, int x, int y, t_thread *thr)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	double			norm;
	size_t			color;

	if (thr->iter < ptrs->max_i)
	{
		norm = thr->iter - (log(log(thr->z)) / log(2));
		r = sin(norm * (0.3 + ptrs->freq) + (5.2 + ptrs->phase)) * 127 + 128;
		g = sin(norm * (0.2 + ptrs->freq) + (4.7 + ptrs->phase)) * 127 + 128;
		b = sin(norm * (0.1 + ptrs->freq) + (3 + ptrs->phase)) * 127 + 128;
		color = (r << 16) + (g << 8) + b;
	}
	else
		color = 0;
	thr->i = (x * ptrs->img_a) + (y * ptrs->img_b);
	ptrs->image[thr->i] = color;
	ptrs->image[++(thr->i)] = color >> 8;
	ptrs->image[++(thr->i)] = color >> 16;
}

static void		ft_get_fractal(t_ptrs *ptrs, char **argv)
{
	if (!ft_strcmp(argv[1], "mandelbrot"))
		ptrs->fractol = 'm';
	else if (!ft_strcmp(argv[1], "drop"))
	{
		ptrs->zoom = 1.979932;
		ptrs->fractol = 'd';
	}
	else if (!ft_strcmp(argv[1], "buffalo"))
		ptrs->fractol = 'b';
	else if (!ft_strcmp(argv[1], "tricorn"))
		ptrs->fractol = 't';
	else if (!ft_strcmp(argv[1], "julia"))
	{
		ptrs->c_r = -0.6;
		ptrs->c_i = 0.45;
		ptrs->fractol = 'j';
	}
	else
	{
		ptrs->zoom = 0.038047;
		ptrs->mx = -1.733187;
		ptrs->my = -0.026327;
		ptrs->fractol = 's';
	}
}

static int		ft_init_graphics(t_ptrs *ptrs, char **argv)
{
	ft_ptrs_init(ptrs);
	ft_get_fractal(ptrs, argv);
	ft_put_image(ptrs);
	mlx_hook(ptrs->win_ptr, 4, 1L << 2, ft_wheel, ptrs);
	mlx_hook(ptrs->win_ptr, 6, 1L << 6, ft_mouse, ptrs);
	mlx_hook(ptrs->win_ptr, 2, 5, ft_keys, ptrs);
	mlx_hook(ptrs->win_ptr, 17, 1L << 17, ft_mouse_close, ptrs);
	mlx_loop(ptrs->mlx_ptr);
	return (0);
}

int				main(int argc, char **argv)
{
	t_ptrs	*ptrs;

	if (argc != 2 || !(!ft_strcmp(argv[1], "mandelbrot")
		|| !ft_strcmp(argv[1], "julia") || !ft_strcmp(argv[1], "ship")
		|| !ft_strcmp(argv[1], "drop") || !ft_strcmp(argv[1], "buffalo")
		|| !ft_strcmp(argv[1], "tricorn")))
	{
		ft_printf("\tusage: ./fractol [ mandelbrot | julia |");
		ft_printf(" ship | drop | tricorn | buffalo ]\n");
		return (1);
	}
	if (!(ptrs = (t_ptrs *)malloc(sizeof(t_ptrs))))
	{
		free(ptrs);
		return (1);
	}
	ft_init_graphics(ptrs, argv);
	return (0);
}
