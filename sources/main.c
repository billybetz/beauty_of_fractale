/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:33:27 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/27 11:10:34 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_env(t_env *env)
{
	env->mandelbrot = malloc(sizeof(t_mandelbrot));
	env->julia = malloc(sizeof(t_julia));
	env->event = malloc(sizeof(t_event));
	env->mlx = malloc(sizeof(t_mlx));
	env->color = malloc(sizeof(t_color));
	env->matrix = malloc(sizeof(t_matrix));
	env->img = malloc(sizeof(t_image));
	env->fractale3 = malloc(sizeof(t_fractale3));
	RED_KEY = 50;
	GREEN_KEY = 50;
	BLUE_KEY = 50;
	NUANCE = 0;
	X_MOUSE = 0.285;
	Y_MOUSE = 0.013;
	MOUSE_ON = 0;
	X_MANDELBROT = 0;
	Y_MANDELBROT = 0;
	X_JULIA = 0;
	Y_JULIA = 0;
	ZOOM_M = 1;
	ZOOM_J = 1;
	ITER_MAX_M = 70;
	ITER_MAX_J = 50;
}

static int		get_arg(t_env *env, char *av)
{
	if ((ft_strcmp(av, "mandelbrot")) == 0)
		env->f_name = ft_strdup("mandelbrot");
	else if ((ft_strcmp(av, "julia")) == 0)
		env->f_name = ft_strdup("julia");
	else if ((ft_strcmp(av, "fractale3")) == 0)
		env->f_name = ft_strdup("fractale3");
	else
		return (0);
	return (1);
}

int				main(int ac, char **av)
{
	t_env	env;

	init_env(&env);
	if (ac != 2)
		return ((int)(ft_failure("usage: ./fractol [fractale_name]\nValid name : \n\t- mandelbrot\n\t- julia\n", 0)));
	if (get_arg(&env, av[1]) ==  0)
		return ((int)(ft_failure("usage: ./fractol [fractale_name]\nValid name : \n\t- mandelbrot\n\t- julia\n", 0)));
	env.mlx->ptr_mlx = mlx_init();
	printf("mlx_init\n");
	env.mlx->ptr_win = mlx_new_window(env.mlx->ptr_mlx, WIDHT_WIN,
			HEIGHT_WIN, "FRACTOL");
	env.img->ptr_img = mlx_new_image(env.mlx->ptr_mlx, WIDHT_IMG, HEIGHT_IMG);
	env.img->bits_img = mlx_get_data_addr(env.img->ptr_img, &(env.img->bpp),
			&(env.img->size_line), &(env.img->end));
	draw_fract(&env);
	mlx_mouse_hook(env.mlx->ptr_win, mouse_events, &env);
	mlx_do_key_autorepeaton(env.mlx->ptr_mlx);
	mlx_hook(env.mlx->ptr_win, 6, 1L << 6, pos_mouse_events, &env);
	mlx_hook(env.mlx->ptr_win, 2, 0, key_events, &env);
	mlx_loop(env.mlx->ptr_mlx);
	return (0);
}
