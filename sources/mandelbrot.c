/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 11:45:25 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/27 11:11:13 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbrot(t_env *env)
{
	double	c[2];
	double	z[2];
	double	tmp;
	int		x;
	int		iter;

	x = 0;
	while (x < WIDHT_IMG * HEIGHT_IMG)
	{
		z[0] = 0;
		z[1] = 0;
		iter = 0;
		c[0] = (double)(x % WIDHT_IMG - WIDHT_IMG / 2) * ZOOM_M / WIDHT_IMG + X_MANDELBROT;
		c[1] = (double)(x / WIDHT_IMG - HEIGHT_IMG / 2) * ZOOM_M / HEIGHT_IMG + Y_MANDELBROT;
		while (iter < ITER_MAX_M && sqrt(z[0] * z[0] + z[1] * z[1]) < 3)
		{
			tmp = z[0];
			z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
			z[1] = z[1] * tmp * 2 + c[1];
			iter++;
		}
		if (iter < ITER_MAX_M)
		{
			ft_get_color(env, iter);
			ft_write_pixel(env, x % WIDHT_IMG, x / WIDHT_IMG);
		}
		x++;
	}
}
