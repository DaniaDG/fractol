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
	if (key == SPACE)
	{
		if (ptr->space_button == NOT_PRESSED)
			ptr->space_button = IS_PRESSED;
		else
			ptr->space_button = NOT_PRESSED;
	}
	if (key == R_BUTTON)
		redraw(ptr);
	if (key == N_BUTTON)
		change_formula(ptr);
	if (key == C_BUTTON)
		change_color_formula(ptr);
	return (0);
}

int		mouse_press(int key, int x, int y, t_ptr *ptr)
{
	if (key == SCROLL_UP || key == SCROLL_DOWN)
		change_zoom(key, x, y, ptr);
	if (key == MOUSE_LEFT && x >= 0 && y >= 0)
	{
		ptr->mouse_left = IS_PRESSED;
		ptr->mouse->curr_x = x;
		ptr->mouse->curr_y = y;
	}
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
	if (ptr->space_button == NOT_PRESSED)
	{
		ptr->k.x = 4 * ((double)x / IMG_W - 0.5);
		ptr->k.y = 4 * ((double)(IMG_H - y) / IMG_H - 0.5);
		thread(ptr);
	}
	if (ptr->mouse_left == IS_PRESSED)
		move_img_by_mouse(x, y, ptr);
	return (0);
}
