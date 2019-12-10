/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:46:07 by bsausage          #+#    #+#             */
/*   Updated: 2019/10/22 09:07:49 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	sum(t_complex a, t_complex b)
{
	t_complex	z;

	z.x = a.x + b.x;
	z.y = a.y + b.y;
	return (z);
}

t_complex	multiply(t_complex a, t_complex b)
{
	t_complex	z;

	z.x = a.x * b.x - a.y * b.y;
	z.y = a.x * b.y + a.y * b.x;
	return (z);
}

t_complex	sqr_pow(t_complex c)
{
	t_complex	z;

	z.x = c.x * c.x - c.y * c.y;
	z.y = 2 * c.x * c.y;
	return (z);
}


t_complex	get_complex(int x, int y, t_ptr *ptr)
{
	t_complex	c;

	c.x = ptr->min.x + x * ((ptr->max.x - ptr->min.x) / (IMG_W - 1));
	c.y = ptr->max.y - y * ((ptr->max.y - ptr->min.y) / (IMG_H - 1));
	return (c);
}
