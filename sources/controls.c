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

int		key_press(int key, t_ptr *ptr)
{
	if (key == ESC)
		exit(0);
	if (key == Q_BUTTON || key == W_BUTTON ||
		key == PLUS_NUM || key == MINUS_NUM)
	{
		ft_bzero(ptr->data_addr, IMG_W * IMG_H * (ptr->bits_per_pixel / 8));
		ptr->max_iteration += change_max_iteration(key, ptr);
		thread(ptr);
	}
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move_img(key, ptr);
	if (key == J_BUTTON)
	{
		if (ptr->is_julia == 0)
			ptr->is_julia = 1;
		else
			ptr->is_julia = 0;
	}
	return (0);
}

int		mouse_press(int key, int x, int y, t_ptr *ptr)
{
	if (key == SCROLL_UP || key == SCROLL_DOWN)
		change_zoom(key, x, y, ptr);
	if (key == MOUSE_LEFT && x >= 0 && y >= 0)
		ptr->mouse_left = IS_PRESSED;
	return (0);
}

int		mouse_release(int key, int x, int y, t_ptr *ptr)
{
	if (key == MOUSE_LEFT && x >= 0 && y >= 0)
		ptr->mouse_left = NOT_PRESSED;
	return (0);
}

int		mouse_move(int x, int y, t_ptr *ptr)
{
	t_complex	delta;
	t_complex	d;

	if (ptr->is_julia)
	{
		ptr->k.x = 4 * ((double)x / IMG_W - 0.5);
		ptr->k.y = 4 * ((double)(IMG_H - y) / IMG_H - 0.5);
	}
	else if (ptr->mouse_left == IS_PRESSED)
	{
		delta.x = ptr->max.x - ptr->min.x;
		delta.y = ptr->max.y - ptr->min.y;
		ptr->mouse->prev_x = ptr->mouse->curr_x;
		ptr->mouse->prev_y = ptr->mouse->curr_y;
		ptr->mouse->curr_x = x;
		ptr->mouse->curr_y = y;
		d.x = ptr->mouse->curr_x - ptr->mouse->prev_x;
		d.y = ptr->mouse->curr_y - ptr->mouse->prev_y;
		ptr->min.x += d.x <= 0 ? delta.x * 0.01 : delta.x * (-0.01);
		ptr->max.x += d.x <= 0 ? delta.x * 0.01 : delta.x * (-0.01);
		ptr->min.y += d.y >= 0 ? delta.y * 0.01 : delta.y * (-0.01);
		ptr->max.y += d.y >= 0 ? delta.y * 0.01 : delta.y * (-0.01);
	}
	thread(ptr);
	return (0);
}
