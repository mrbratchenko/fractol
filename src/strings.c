/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbratche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 20:57:15 by sbratche          #+#    #+#             */
/*   Updated: 2018/05/13 20:57:18 by sbratche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractal.h"

static void		ft_put_and_free_str(t_ptrs *ptrs, char *free_str,
															char *str, int i)
{
	free(free_str);
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 25, i, 0xffffff, str);
	free(str);
}

static void		ft_more_strings(t_ptrs *ptrs)
{
	char		*free_str;
	char		*str;

	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 25, 75, 0xffffff,
		"color change: 'pageUp'/'pageDown'/'home'/'end'");
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 25, 100, 0xffffff,
		"move: arrows");
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 25, 125, 0xffffff,
		"zoom: mouse wheel");
	str = ft_itoa(ptrs->max_i);
	free_str = str;
	str = ft_strjoin("iteration: ", free_str);
	ft_put_and_free_str(ptrs, free_str, str, 150);
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 205, 150, 0xffffff,
		"('+' or '-')");
	str = ft_itoa(ptrs->escape);
	free_str = str;
	str = ft_strjoin("escape radius: ", free_str);
	ft_put_and_free_str(ptrs, free_str, str, 175);
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 235, 175, 0xffffff,
		"(other '+' or '-')");
}

void			ft_strings(t_ptrs *ptrs)
{
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 25, 5, 0xffffff,
		"CURRENT SET:  ");
	if (ptrs->fractol == 'm')
		mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 100, 25, 0x00FF00,
			"mandelbrot");
	else if (ptrs->fractol == 'j')
		mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 100, 25, 0x00FF00,
			"julia");
	else if (ptrs->fractol == 's')
		mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 100, 25, 0x00FF00,
			"burning ship");
	else if (ptrs->fractol == 'd')
		mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 100, 25, 0x00FF00,
			"mandeldrop");
	else if (ptrs->fractol == 't')
		mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 100, 25, 0x00FF00,
			"tricorn");
	else if (ptrs->fractol == 'b')
		mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 100, 25, 0x00FF00,
			"buffalo");
	mlx_string_put(ptrs->mlx_ptr, ptrs->win_ptr, 25, 50, 0xffffff,
		"(flip: 'j', 'm', 's', 'd', 't', 'b' or enter)");
	ft_more_strings(ptrs);
	mlx_destroy_image(ptrs->mlx_ptr, ptrs->img_ptr);
}
