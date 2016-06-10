/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 13:52:45 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/27 11:11:00 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_fract(t_env *env)
{
	mlx_destroy_image(env->mlx->ptr_mlx, env->img->ptr_img);
	env->img = malloc(sizeof(t_image));
	env->img->ptr_img = mlx_new_image(env->mlx->ptr_mlx, 1300, 1300);
	env->img->bits_img = mlx_get_data_addr(env->img->ptr_img, &(env->img->bpp),
			&(env->img->size_line), &(env->img->end));
	if (ft_strcmp(env->f_name, "mandelbrot") == 0)
		draw_mandelbrot(env);
	else if (ft_strcmp(env->f_name, "julia") == 0)
		draw_julia(env);
	// else if (ft_strcmp(env->f_name, "fractale3") == 0)
	// 	draw_fractale3(env);
	mlx_put_image_to_window(env->mlx->ptr_mlx, env->mlx->ptr_win,
		env->img->ptr_img, 0, 0);
}
