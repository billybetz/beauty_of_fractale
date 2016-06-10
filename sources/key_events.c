/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 12:29:57 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/23 19:55:43 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	int	event_color(int keycode, t_env *env)
{
	if (keycode == KEY_I)
		RED_KEY++;
	else if (keycode == KEY_O)
		GREEN_KEY++;
	else if (keycode == KEY_P)
		BLUE_KEY++;
	else if (keycode == KEY_C)
		NUANCE += 5;
	else if (keycode == KEY_V)
		NUANCE -= 5;
	draw_fract(env);
	return (0);
}

static	int	event_divers(int keycode, t_env *env)
{
	if (keycode == KEY_ESC)
		end_program();
	else if (keycode == KEY_SPACE)
		MOUSE_ON = (MOUSE_ON == 0) ? 1 : 0;
	else if (keycode == KEY_R)
		refresh_fractale(env);
	draw_fract(env);
	return (0);
}

static	int	event_movement(int keycode, t_env *env)
{
	if (keycode == KEY_UP && ft_strcmp(env->f_name, "mandelbrot") == 0)
		Y_MANDELBROT -= 0.1 * ZOOM_M;
	else if (keycode == KEY_DOWN && ft_strcmp(env->f_name, "mandelbrot") == 0)
		Y_MANDELBROT += 0.1 * ZOOM_M;
	else if (keycode == KEY_RIGHT && ft_strcmp(env->f_name, "mandelbrot") == 0)
		X_MANDELBROT += 0.1 * ZOOM_M;
	else if (keycode == KEY_LEFT && ft_strcmp(env->f_name, "mandelbrot") == 0)
		X_MANDELBROT -= 0.1 * ZOOM_M;
	else if (keycode == KEY_UP && ft_strcmp(env->f_name, "julia") == 0)
		Y_JULIA -= 0.1 * ZOOM_J;
	else if (keycode == KEY_DOWN && ft_strcmp(env->f_name, "julia") == 0)
		Y_JULIA += 0.1 * ZOOM_J;
	else if (keycode == KEY_RIGHT && ft_strcmp(env->f_name, "julia") == 0)
		X_JULIA += 0.1 * ZOOM_J;
	else if (keycode == KEY_LEFT && ft_strcmp(env->f_name, "julia") == 0)
		X_JULIA -= 0.1 * ZOOM_J;
	draw_fract(env);
	return (0);
}

static	int	event_swap(int keycode, t_env *env)
{
	if ((ft_strcmp(env->f_name, "julia") != 0) && keycode == KEY_J)
	{
		free(env->f_name);
		env->f_name = ft_strdup("julia");
	}
	else if ((ft_strcmp(env->f_name, "mandelbrot") != 0) && keycode == KEY_M)
	{
		free(env->f_name);
		env->f_name = ft_strdup("mandelbrot");
	}
	draw_fract(env);
	return (0);
}

int			key_events(int keycode, t_env *env)
{
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == KEY_J || keycode == KEY_M)
		return (event_swap(keycode, env));
	else if (keycode == KEY_I || keycode == KEY_O || keycode == KEY_P || 
		keycode == KEY_C || keycode == KEY_V)
		return (event_color(keycode, env));
	else if (keycode == KEY_ESC || keycode == KEY_SPACE || keycode == KEY_R)
		return (event_divers(keycode, env));
	else if (keycode == KEY_UP || keycode == KEY_DOWN || keycode == KEY_LEFT || 
		keycode == KEY_RIGHT)
		return (event_movement(keycode, env));
	return (0);
}
