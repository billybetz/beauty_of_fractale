/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractale3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 23:43:49 by bbetz             #+#    #+#             */
/*   Updated: 2016/06/06 23:43:51 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractale3(t_env *env)
{
	// double	c[2];
	// double	z[2];
	// double	tmp;
	// int		x;
	// int		iter;

	// x = 0;
	// while (x < WIDHT_IMG * HEIGHT_IMG)
	// {
	// 	z[0] = 0;
	// 	z[1] = 0;
	// 	iter = 0;
	// 	c[0] = (double)(x % WIDHT_IMG - WIDHT_IMG / 2) * ZOOM / WIDHT_IMG + X_TRANSLATE;
	// 	c[1] = (double)(x / WIDHT_IMG - HEIGHT_IMG / 2) * ZOOM / HEIGHT_IMG + Y_TRANSLATE;
	// 	while (iter < ITER_MAX && sqrt(z[0] * z[0] + z[1] * z[1]) < 3)
	// 	{
	// 		tmp = z[0];
	// 		z[0] = z[0] * z[0] - z[1] * z[1] + c[0];
	// 		z[1] = z[1] * tmp * 2 + c[1];
	// 		iter++;
	// 	}
	// 	if (iter < ITER_MAX)
	// 	{
	// 		ft_get_color(env, iter);
	// 		ft_write_pixel(env, x % WIDHT_IMG, x / WIDHT_IMG);
	// 	}
	// 	x++;
	// }
}
