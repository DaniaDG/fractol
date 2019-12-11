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

/*static double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}*/

static double	percent(int start, int end, int current)
{
	double delta;

	delta = end - start;
	return ((delta == 0) ? 0.0 : (current / delta));
}

/*int				color(int current, int min, int max, int color)
{
	int		r;
	int		g;
	int		b;
	double	k;

	k = percent(min, max, current);
	r = (int)(red(color) + (red(RED) - red(color)) * k);
	g = (int)(green(color) + (green(RED) - green(color)) * k);
	b = (int)(blue(color) + (blue(RED) - blue(color)) * k);
	return (rgb(r, g, b));
}*/

int				color(int current, int min, int max, int color1, int color2)
{
	int		r;
	int		g;
	int		b;
	double	k;

	k = percent(min, max, current);
	r = (int)(red(color1) + (red(color2) - red(color1)) * k);
	g = (int)(green(color1) + (green(color2) - green(color1)) * k);
	b = (int)(blue(color1) + (blue(color2) - blue(color1)) * k);
	return (rgb(r, g, b));
}
