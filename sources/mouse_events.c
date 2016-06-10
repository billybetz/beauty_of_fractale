/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 14:56:14 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/30 14:56:18 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	void	zoom_mouse(t_env *env, double x, double y, int button)
{
	if (button == 5 && ft_strcmp(env->f_name, "mandelbrot") == 0)
	{
		ZOOM_M /= 2;
		ITER_MAX_M += 7;
		X_MANDELBROT += (X_MOUSE - X_MANDELBROT) / 2;
		Y_MANDELBROT += (Y_MOUSE - Y_MANDELBROT) / 2;
	}
	else if (button == 5 && (ft_strcmp(env->f_name, "julia") == 0))
	{
		ZOOM_J /= 2;
		ITER_MAX_M += 7;
		X_JULIA += (X_MOUSE - X_JULIA) / 2;
		Y_JULIA += (Y_MOUSE - Y_JULIA) / 2;
	}
	else if (button == 4 && ft_strcmp(env->f_name, "mandelbrot") == 0)
	{
		ZOOM_M *= 2;
		ITER_MAX_M -= 7;
		X_MANDELBROT -= (X_MOUSE - X_MANDELBROT) / 2;
		Y_MANDELBROT -= (Y_MOUSE - Y_MANDELBROT) / 2;
	}
	else if (button == 4 && (ft_strcmp(env->f_name, "julia") == 0))
	{
		ZOOM_J /= 2;
		ITER_MAX_J += 7;
		X_JULIA += (X_MOUSE - X_JULIA) / 2;
		Y_JULIA += (Y_MOUSE - Y_JULIA) / 2;
	}
}

int		mouse_events(int button, int x, int y, t_env *env)
{
	ft_putnbr(button);
	ft_putchar('\n');
	if (button == 5 || button == 4)
		zoom_mouse(env, x, y, button);
	draw_fract(env);
	return (0);
}

int		pos_mouse_events(int x, int y, t_env *env)
{
	if ((ft_strcmp(env->f_name, "mandelbrot") == 0))
	{
		X_MOUSE = (double)(x - (WIDHT_IMG / 2)) / WIDHT_IMG * ZOOM_M + X_MANDELBROT;
		Y_MOUSE = (double)(y - (HEIGHT_IMG / 2)) / HEIGHT_IMG * ZOOM_M + Y_MANDELBROT;
	}
	else if ((ft_strcmp(env->f_name, "julia") == 0) && MOUSE_ON == 1)
	{
		X_MOUSE = (double)(x - (WIDHT_IMG / 2)) / WIDHT_IMG * ZOOM_J + X_JULIA;
		Y_MOUSE = (double)(y - (HEIGHT_IMG / 2)) / HEIGHT_IMG * ZOOM_J + Y_JULIA;
	}
	draw_fract(env);
	return (0);
}