/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 15:41:56 by bsausage          #+#    #+#             */
/*   Updated: 2019/11/09 15:41:57 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_pixel(t_ptr *ptr, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < IMG_W && y >= 0 && y < IMG_H)
	{
		i = (x * ptr->bits_per_pixel / 8) + (y * ptr->size_line);
		ptr->data_addr[i] = blue(color);
		ptr->data_addr[++i] = green(color);
		ptr->data_addr[++i] = red(color);
	}
}

void		draw(t_ptr *ptr)
{
	int			x;
	int			y;
	int			i;
	t_complex	c;
	t_complex	z;

	ft_bzero(ptr->data_addr, IMG_W * IMG_H * (ptr->bits_per_pixel / 8));
	x = 0;
	while (x < IMG_W)
	{
		y = 0;
		while (y < IMG_H)
		{
			c = get_complex(x, y, ptr);
			z = c;
			i = 1;
			while (i <= ptr->max_iteration)
			{
				z = sum(sqr_pow(z), c);
				if (z.x * z.x + z.y * z.y > 4.0)
				{
					put_pixel(ptr, x, y, color(i, 0, ptr->max_iteration, C1, C2));
					break ;
				}
				i++;
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
}
//
//
//
//
//
void		*draw1(void *arg)
{
	int			x;
	int			y;
	int			i;
	t_complex	c;
	t_complex	z;
	t_ptr		*ptr = (t_ptr *)arg;

	x = 0;
	while (x < IMG_W)
	{
		y = ptr->y_begin;
		while (y < ptr->y_end)
		{
			c = get_complex(x, y, ptr);
			z = c;
			i = 1;
			while (i <= ptr->max_iteration)
			{
				z = sum(sqr_pow(z), c);
				if (z.x * z.x + z.y * z.y > 4.0)
				{
					put_pixel(ptr, x, y, color(i, 0, ptr->max_iteration, C1, C2));
					break ;
				}
				i++;
			}
			y++;
		}
		x++;
	}
	return (SUCCESS);
}

void		*draw2(void *arg)
{
	int			x;
	int			y;
	int			i;
	t_complex	c;
	t_complex	z;
	t_ptr		*ptr = (t_ptr *)arg;

	//ft_bzero(ptr->data_addr, IMG_W * IMG_H * (ptr->bits_per_pixel / 8));
	x = 0;
	while (x < IMG_W)
	{
		y = 250;
		while (y < 500)
		{
			c = get_complex(x, y, ptr);
			z = c;
			i = 1;
			while (i <= ptr->max_iteration)
			{
				z = sum(sqr_pow(z), c);
				if (z.x * z.x + z.y * z.y > 4.0)
				{
					put_pixel(ptr, x, y, color(i, 0, ptr->max_iteration, C1, C2));
					break ;
				}
				i++;
			}
			y++;
		}
		x++;
	}
	//mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	return (SUCCESS);
}

void		*draw3(void *arg)
{
	int			x;
	int			y;
	int			i;
	t_complex	c;
	t_complex	z;
	t_ptr		*ptr = (t_ptr *)arg;

	//ft_bzero(ptr->data_addr, IMG_W * IMG_H * (ptr->bits_per_pixel / 8));
	x = 0;
	while (x < IMG_W)
	{
		y = 500;
		while (y < 750)
		{
			c = get_complex(x, y, ptr);
			z = c;
			i = 1;
			while (i <= ptr->max_iteration)
			{
				z = sum(sqr_pow(z), c);
				if (z.x * z.x + z.y * z.y > 4.0)
				{
					put_pixel(ptr, x, y, color(i, 0, ptr->max_iteration, C1, C2));
					break ;
				}
				i++;
			}
			y++;
		}
		x++;
	}
	//mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	return (SUCCESS);
}

void		*draw4(void *arg)
{
	int			x;
	int			y;
	int			i;
	t_complex	c;
	t_complex	z;
	t_ptr		*ptr = (t_ptr *)arg;

	//ft_bzero(ptr->data_addr, IMG_W * IMG_H * (ptr->bits_per_pixel / 8));
	x = 0;
	while (x < IMG_W)
	{
		y = 750;
		while (y < 1000)
		{
			c = get_complex(x, y, ptr);
			z = c;
			i = 1;
			while (i <= ptr->max_iteration)
			{
				z = sum(sqr_pow(z), c);
				if (z.x * z.x + z.y * z.y > 4.0)
				{
					put_pixel(ptr, x, y, color(i, 0, ptr->max_iteration, C1, C2));
					break ;
				}
				i++;
			}
			y++;
		}
		x++;
	}
	//mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	return (SUCCESS);
}