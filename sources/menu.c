/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:08:15 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/14 16:08:17 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			put_pixel1(t_ptr *ptr, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < IMG_W && y >= 0 && y < IMG_H)
	{
		i = (x * ptr->bits_per_pixel / 8) + (y * ptr->size_line1);
		ptr->data_addr1[i] = blue(color);
		ptr->data_addr1[++i] = green(color);
		ptr->data_addr1[++i] = red(color);
	}
}

static	void		mandelbrot1(int x, int y, t_ptr *ptr)
{
	t_complex	c;
	t_complex	z;
	int			i;

	c = get_complex(x, y, ptr);
	z = c;
	i = 1;
	while (i <= 50)
	{
		z = sum(sqr_pow(z), c);
		if (z.x * z.x + z.y * z.y > 4.0)
		{
			put_pixel1(ptr, x, y, color(i, 50, C1, C2));
			return ;
		}
		i++;
	}
}

void				 draw_menu(t_ptr *ptr)
{
	int		x;
	int		y;

	ft_bzero(ptr->data_addr1, MENU_W * MENU_H * (ptr->bits_per_pixel / 8));
	x = 0;
	while (x < MENU_W)
	{
		y = 0;
		while (y < MENU_H)
		{
			mandelbrot1(x, y, ptr);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img1, 1001, 0);
}
