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

t_complex	fractal(t_complex z, t_complex c)
{
	return (sum(multiply(z, z), c));
}

void		draw(t_ptr *ptr)
{
	int			x = 0;
	int			y = 0;
	int			i = 1;
	t_complex	z;
	t_complex 	c;

	while (x < IMG_W)
	{
		y = 0;
		while (y < IMG_H)
		{
			c = get_complex(x, y, ptr);
			while (i <= ptr->max_iteration)
			{
				z = fractal(z, c);
				if (z.x * z.x + z.y +z.y > 4.0)
				{
					put_pixel(ptr, x, y, RED);
					break ;
				}
				i++;
			}
			y++;
		}
		x++;
	}
}
