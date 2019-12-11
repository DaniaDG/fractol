/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formulas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:58:54 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/11 18:58:56 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(int x, int y, t_ptr *ptr)
{
	t_complex	c;
	t_complex	z;
	int			i;

	c = get_complex(x, y, ptr);
	z = c;
	i = 1;
	while (i <= ptr->max_iteration)
	{
		z = sum(sqr_pow(z), c);
		if (z.x * z.x + z.y * z.y > 4.0)
		{
			put_pixel(ptr, x, y, get_color(i, ptr));
			return ;
		}
		i++;
	}
}

void	burning_ship(int x, int y, t_ptr *ptr)
{
	int			i;
	t_complex	z;
	t_complex	tmp;
	t_complex	c;

	i = 1;
	c = get_complex(x, y, ptr);
	z = c;
	while (i <= ptr->max_iteration)
	{
		tmp.x = z.x;
		z.x = fabs(pow(tmp.x, 2.0) - pow(tmp.y, 2.0) + c.x);
		z.y = fabs(2.0 * tmp.x * z.y + c.y);
		if (z.x * z.x + z.y * z.y > 4.0)
		{
			put_pixel(ptr, x, y, get_color(i, ptr));
			return ;
		}
		i++;
	}
}

void		julia(int x, int y, t_ptr *ptr)
{
	t_complex	z;
	int			i;

	z = get_complex(x, y, ptr);
	i = 1;
	while (i <= ptr->max_iteration)
	{
		z = sum(sqr_pow(z), ptr->k);
		if (z.x * z.x + z.y * z.y > 4.0)
		{
			put_pixel(ptr, x, y, get_color(i, ptr));
			return ;
		}
		i++;
	}
}
