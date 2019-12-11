/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 12:54:37 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/07 12:54:38 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	percent(int start, int end, int current)
{
	double delta;

	delta = end - start;
	return ((delta == 0) ? 0.0 : (current / delta));
}

static int		color(int current, int max, int color1, int color2)
{
	int		r;
	int		g;
	int		b;
	int		min;
	double	k;

	min = 0;
	k = percent(min, max, current);
	r = (int)(red(color1) + (red(color2) - red(color1)) * k);
	g = (int)(green(color1) + (green(color2) - green(color1)) * k);
	b = (int)(blue(color1) + (blue(color2) - blue(color1)) * k);
	return (rgb(r, g, b));
}

int				get_color(int i, t_ptr *ptr)
{
	int		step;

	step = ptr->max_iteration / 4;
	if (i == 1)
		return (C1);
	if (i <= step)
		return (color(i, step, C1, C2));
	else if (i <= 2 * step)
		return (color(i - step, step, C2, C3));
	else if (i <= 3 * step)
		return (color(i - 2 * step, step, C3, C4));
	else if (i < 4 * step)
		return (color(i - 3 * step, step, C4, C5));
	return (C5);
}
