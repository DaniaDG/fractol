/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 12:54:37 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/07 12:54:38 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		change_max_iteration(int key, t_ptr *ptr)
{
	if (key == Q_BUTTON)
		return (ptr->max_iteration == 1 ? 0 : -1);
	return (1);
}

int		change_zoom(int key, int x, int y, t_ptr *ptr)
{
	t_complex	mouse;
	double		zoom;
	double		i;

	mouse = get_complex(x, y, ptr);
	if (key == SCROLL_UP)
		zoom = 0.80;
	else
		zoom = 1.20;
	i = 1.0 / zoom;
	ptr->min.x = mouse.x + ((ptr->min.x - mouse.x) * i);
	ptr->min.y = mouse.y + ((ptr->min.y - mouse.y) * i);
	ptr->max.x = mouse.x + ((ptr->max.x - mouse.x) * i);
	ptr->max.y = mouse.y + ((ptr->max.y - mouse.y) * i);
	draw(ptr);
	return (0);
}

int		move_img(int key, t_ptr *ptr)
{
	if (key == UP || key == DOWN)
		ptr->move_y += key == UP ? 1 : -1;
	if (key == LEFT || key == RIGHT)
		ptr->move_x += key == RIGHT ? 1 : -1;
	return (0);
}

int		key_press(int key, t_ptr *ptr)
{
	if (key == ESC)
		exit(0);
	if (key == Q_BUTTON || key == W_BUTTON)
		ptr->max_iteration += change_max_iteration(key, ptr);
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move_img(key, ptr);
	draw(ptr);
	return (0);
}

int		mouse_press(int key, int x, int y, t_ptr *ptr)
{
	if (key == SCROLL_UP || key == SCROLL_DOWN)
		change_zoom(key, x, y, ptr);
	return (0);
}
