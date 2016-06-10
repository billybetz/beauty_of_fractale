/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divers.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 11:37:09 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/23 19:56:08 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	end_program(void)
{
	exit(ft_success("Program closed", 0));
}

void	refresh_fractale(t_env *env)
{
	if ((ft_strcmp(env->f_name, "mandelbrot") == 0))
	{
		X_MANDELBROT = 0;
		Y_MANDELBROT = 0;
		ITER_MAX_M = 70;
		ZOOM_M = 1;
	}
	else if ((ft_strcmp(env->f_name, "julia") == 0))
	{
		X_JULIA = 0;
		Y_JULIA = 0;
		ITER_MAX_J = 50;
		ZOOM_J = 1;
	}
}
