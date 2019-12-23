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
			put_pixel(ptr, x, y, ptr->color_f(i, ptr));
			return ;
		}
		i++;
	}
}

void		burning_ship(int x, int y, t_ptr *ptr)
{
	int			i;
	t_complex	z;
	t_complex	c;

	i = 1;
	c = get_complex(x, y, ptr);
	z = c;
	while (i <= ptr->max_iteration)
	{
		z.x = fabs(z.x);
		z.y = -fabs(z.y);
		z = sum(sqr_pow(z), c);
		if (z.x * z.x + z.y * z.y > 4.0)
		{
			put_pixel(ptr, x, y, ptr->color_f(i, ptr));
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
			put_pixel(ptr, x, y, ptr->color_f(i, ptr));
			return ;
		}
		i++;
	}
}

void		test(int x, int y, t_ptr *ptr)
{
	t_complex	c;
	t_complex	z;
	int			i;
	int			tmp_x;

	c = get_complex(x, y, ptr);
	z = c;
	i = 1;
	while (i <= ptr->max_iteration)
	{
		tmp_x = z.x;
		z.x = pow(z.x, 3.0) - 3 * z.x * z.y;
		z.y = 3 * tmp_x * tmp_x * z.y - z.y * z.y;
		if (z.x * z.x + z.y * z.y > 4.0)
		{
			put_pixel(ptr, x, y, ptr->color_f(i, ptr));
			return ;
		}
		i++;
	}
}

int			change_formula(t_ptr *ptr)
{
	if (ptr->formula == &mandelbrot)
	{
		ptr->formula = &julia;
		ptr->space_button = NOT_PRESSED;
		redraw(ptr);
		return (0);
	}
	if (ptr->formula == &julia)
	{
		ptr->formula = &burning_ship;
		redraw(ptr);
		return (0);
	}
	ptr->formula = &mandelbrot;
	redraw(ptr);
	return (0);
}
