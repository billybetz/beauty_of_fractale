/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 12:35:31 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/27 11:11:21 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia(t_env *env)
{
	double	c[2];
	double	z[2];
	double	tmp;
	int		x;
	int		iter;

	x = 0;
	while (x < WIDHT_IMG * HEIGHT_IMG)
	{
		z[0] = (double)(x % WIDHT_IMG - WIDHT_IMG / 2) / WIDHT_IMG * 2;
		z[1] = (double)(x / WIDHT_IMG - HEIGHT_IMG / 2) / HEIGHT_IMG * 2;
		iter = 0;
		c[0] = X_MOUSE;
		c[1] = Y_MOUSE;
		while (iter < ITER_MAX_J && sqrt(z[0] * z[0] + z[1] * z[1]) < 2)
		{
			tmp = z[0];
			z[0] = z[0] * z[0] - z[1] * z[1] + c[0] + X_JULIA;
			z[1] = z[1] * tmp * 2 + c[1] + Y_JULIA;
			iter++;
		}
		if (iter < ITER_MAX_J)
		{
			ft_get_color(env, iter);
			ft_write_pixel(env, x % WIDHT_IMG, x / WIDHT_IMG);
		}
		x++;
	}
}