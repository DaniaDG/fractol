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

void		put_pixel(t_ptr *ptr, int x, int y, int color)
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

void		*draw(void *arg)
{
	int			x;
	int			y;
	t_ptr		*ptr;

	ptr = (t_ptr *)arg;
	x = 0;
	while (x < IMG_W)
	{
		y = ptr->y_begin;
		while (y < ptr->y_end)
		{
			ptr->formula(x, y, ptr);
			y++;
		}
		x++;
	}
	return (SUCCESS);
}
