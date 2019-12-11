/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:39:28 by bsausage          #+#    #+#             */
/*   Updated: 2019/10/21 12:39:29 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include "mlx.h"
# include "libft.h"
# include "colors.h"
# include "keycodes.h"
# include "get_next_line.h"

# define IMG_H		1000
# define IMG_W		1000
# define MENU_H		0
# define MENU_W		0
# define HEIGHT		1000
# define WIDTH		1000
# define MAXTHREADS	16

# define ERROR_CREATE_THREAD -11
# define ERROR_JOIN_THREAD   -12
# define SUCCESS               0

typedef struct		s_complex
{
	double		x;
	double		y;
}					t_complex;

typedef struct		s_color
{
	int			color1;
	int			color2;
}					t_color;

typedef enum
{
	IS_PRESSED,
	NOT_PRESSED
}	t_button;

typedef struct		s_mouse
{
	int			curr_x;
	int			curr_y;
	int			prev_x;
	int			prev_y;
	//t_button	button;
}					t_mouse;

typedef struct		s_ptr
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	double			zoom;
	t_complex		min;
	t_complex		max;
	t_complex		k;
	t_button		mouse_left;
	t_mouse			*mouse;
	t_color			color;
	int				is_julia;
	int				max_iteration;
	int				y_begin;
	int				y_end;
	void			(*formula)(int x, int y, struct s_ptr *ptr);
}					t_ptr;

void		hooks(t_ptr *ptr);
void		error(char *str);
int			turn_off(void *param);
t_ptr		*init_ptr(void);
void		put_pixel(t_ptr *ptr, int x, int y, int color);
int			red(int rgb);
int			green(int rgb);
int			blue(int rgb);
int			rgb(int r, int g, int b);
int			get_color(int i, t_ptr *ptr);
t_complex	sum(t_complex a, t_complex b);
t_complex	multiply(t_complex a, t_complex b);
t_complex	get_complex(int x, int y, t_ptr *ptr);
t_complex	sqr_pow(t_complex c);
void		*draw(void *arg);
void		mandelbrot(int x, int y, t_ptr *ptr);
void		julia(int x, int y, t_ptr *ptr);
int			key_press(int key, t_ptr *ptr);
int			mouse_press(int key, int x, int y, t_ptr *ptr);
int 		mouse_release(int key, int x, int y, t_ptr *ptr);
int 		mouse_move(int x, int y, t_ptr *ptr);
int			change_max_iteration(int key, t_ptr *ptr);
int			change_zoom(int key, int x, int y, t_ptr *ptr);
void		move_img(int key, t_ptr *ptr);
int			thread(t_ptr *ptr);



#endif
