/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:08:16 by sbratche          #+#    #+#             */
/*   Updated: 2018/02/10 15:24:11 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "../libft/inc/libft.h"
# include "../libft/ft_printf/inc/libftprintf.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include <pthread.h>
# define THREADS 4
# define WIN_H 1000
# define WIN_W 1000

typedef struct		s_ptrs
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*image;
	int				img_a;
	int				img_b;
	int				img_c;
	size_t			color;
	char			fractol;
	double			c_r;
	double			c_i;
	double			zoom;
	double			mx;
	double			my;
	int				max_i;
	int				iter;
	double			x;
	double			y;
	int				i;
	double			z;
	double			norm;
	double			phase;
	double			freq;
	int				escape;

}					t_ptrs;

typedef struct		s_thread
{
	int				num;
	double			z;
	double			x;
	int				i;
	double			c_r;
	double			c_i;
	double			c_r2;
	double			c_i2;
	int				iter;
	t_ptrs			*ptrs;
}					t_thread;

int					ft_mouse_close(void);
int					ft_keys(int key, t_ptrs *ptrs);
int					ft_mouse(int x, int y, t_ptrs *ptrs);
int					ft_wheel(int button, int x, int y, t_ptrs *ptrs);
void				ft_put_image(t_ptrs *ptrs);
void				ft_strings(t_ptrs *ptrs);
void				ft_thread_init(t_thread *thr);
void				ft_ptrs_init(t_ptrs *ptrs);
void				ft_map_pixel(t_ptrs *ptrs, int x, int y, t_thread *threads);
void				ft_set_to_zero(double *x, double *y, int *iter);
void				ft_draw_mandelbrot(t_ptrs *ptrs, double y_beg, double y_end,
													t_thread *threads);
void				ft_draw_ship(t_ptrs *ptrs, double y_beg, double y_end,
													t_thread *threads);
void				ft_draw_julia(t_ptrs *ptrs, double y_b, double y_e,
													t_thread *threads);
void				ft_draw_tricorn(t_ptrs *ptrs, double y_beg, double y_end,
																t_thread *thr);
void				ft_draw_buffalo(t_ptrs *ptrs, double y_beg, double y_end,
																t_thread *thr);
void				ft_draw_drop(t_ptrs *ptrs, double y_beg, double y_end,
																t_thread *thr);
#endif
