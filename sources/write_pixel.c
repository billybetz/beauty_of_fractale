/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 15:32:36 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/29 15:32:38 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	ft_get_color(t_env *env, int iter)
{
	R = ((ITER_MAX_M / iter * 42) + (5 * RED_KEY + NUANCE) % 255);
	G = ((ITER_MAX_M / iter * 42) + (5 * GREEN_KEY + NUANCE) % 255);
	B = ((ITER_MAX_M / iter * 42) + (5 * BLUE_KEY + NUANCE) % 255);
}

void	ft_write_pixel(t_env *env, int x, int y)
{
	if (x > 0 && x < WIDHT_IMG && y > 0 && y < HEIGHT_IMG)
	{
		env->img->bits_img[(4 * (x + SIZELINE / 4 * y))] = B;
		env->img->bits_img[(4 * (x + SIZELINE / 4 * y)) + 1] = G;
		env->img->bits_img[(4 * (x + SIZELINE / 4 * y)) + 2] = R;
	}
}