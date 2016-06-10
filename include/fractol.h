/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbetz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:34:12 by bbetz             #+#    #+#             */
/*   Updated: 2016/05/18 16:59:46 by bbetz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_T 17
# define KEY_Y 16
# define KEY_U 32
# define KEY_I 34
# define KEY_O 31
# define KEY_P 35
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_N 45
# define KEY_M 46
# define KEY_ESC 53
# define KEY_SPACE 49
# define KEY_PAD_0 82
# define KEY_PAD_1 83
# define KEY_PAD_2 84
# define KEY_PAD_3 85
# define KEY_PAD_4 86
# define KEY_PAD_5 87
# define KEY_PAD_6 88
# define KEY_PAD_7 89
# define KEY_PAD_8 91
# define KEY_PAD_9 92
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_DEL 51
# define KEY_RET 36
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define SIZELINE env->img->size_line
# define R env->color->r
# define G env->color->g
# define B env->color->b
# define NUANCE env->color->rand
# define RED_KEY env->color->red
# define GREEN_KEY env->color->green
# define BLUE_KEY env->color->blue
# define X_MOUSE env->event->x_mouse
# define Y_MOUSE env->event->y_mouse
# define X_MANDELBROT env->mandelbrot->x
# define Y_MANDELBROT env->mandelbrot->y
# define X_JULIA env->mandelbrot->x
# define Y_JULIA env->mandelbrot->y
# define MOUSE_ON env->event->mouse_on
# define ZOOM_M env->mandelbrot->zoom
# define ZOOM_J env->julia->zoom
# define ITER_MAX_M env->mandelbrot->iter_max
# define ITER_MAX_J env->julia->iter_max
# define WIDHT_IMG 1000
# define HEIGHT_IMG 1000
# define WIDHT_WIN 1000
# define HEIGHT_WIN 1000

typedef struct s_matrix
{
	double	a1;
	double	a2;
	double	a3;
	double	b1;
	double	b2;
	double	b3;
	double	c1;
	double	c2;
	double	c3;
}				t_matrix;

typedef struct	s_image
{
	void		*ptr_img;
	char		*bits_img;
	int			size_line;
	int			bpp;
	int			end;
}				t_image;

typedef struct	s_mlx
{
	void		*ptr_mlx;
	void		*ptr_win;
}				t_mlx;

typedef struct	s_color
{
	double		r;
	double		g;
	double		b;
	int			t;
	int			red;
	int			green;
	int			blue;
	int			rand;
}				t_color;

typedef struct  s_mandelbrot
{
	double		x;
	double		y;
	double		zoom;
	int			iter_max;
}				t_mandelbrot;

typedef struct  s_julia
{
	double		x;
	double		y;
	double		zoom;
	int			iter_max;
}				t_julia;

typedef struct  s_fractale3
{
	double		x;
	double		y;
	double		zoom;
	int			iter_max;
}				t_fractale3;

typedef	struct 	s_event
{
	double		x_mouse;
	double		y_mouse;
	short		mouse_on;
}				t_event;

typedef struct	s_env
{
	t_image			*img;
	t_mlx			*mlx;
	t_color			*color;
	t_matrix		*matrix;
	t_mandelbrot	*mandelbrot;
	t_julia			*julia;
	t_fractale3		*fractale3;
	t_event			*event;
	char			*f_name;
}				t_env;

void			draw_fract(t_env *env);
void			draw_julia(t_env *env);
void			draw_mandelbrot(t_env *env);
void			draw_fractale3(t_env *env);

void			ft_get_color(t_env *env, int iter);
void			ft_write_pixel(t_env *env, int x, int y);

/*
**	==========	**
**	  EVENTS	**
**	==========	**
*/

int				key_events(int keycode, t_env *env);
int				mouse_events(int button, int x, int y, t_env *env);
int				pos_mouse_events(int x, int y, t_env *env);
void			apply_matrix(t_env *env, int i);
void			end_program(void);
void			change_fractale(t_env *env);
void			refresh_fractale(t_env *env);

#endif
