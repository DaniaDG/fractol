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
# include "get_next_line.h"

# define IMG_H		600
# define IMG_W		1080
# define MENU_H		0
# define MENU_W		0
# define HEIGHT		IMG_H + MENU_H
# define WIDTH		IMG_W + MENU_W

typedef struct		s_complex
{
	double		x;
	double		y;
}					t_complex;

typedef struct		s_ptr
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;

	t_complex		min;
	t_complex		max;
	t_complex		c;
	int				max_iteration;
}					t_ptr;

void	hooks(t_ptr *ptr);
void	error(char *str);
int		turn_off(void *param);
t_ptr	*init_ptr(void);
void	put_pixel(t_ptr *ptr, int x, int y, int color);
int		red(int rgb);
int		green(int rgb);
int		blue(int rgb);
int		rgb(int r, int g, int b);
t_complex	sum(t_complex a, t_complex b);
t_complex	multiply(t_complex a, t_complex b);
t_complex	get_complex(int x, int y, t_ptr *ptr);
void		draw(t_ptr *ptr);



#endif
