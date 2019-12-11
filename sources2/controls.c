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
	if (key == Q_BUTTON || key == MINUS_NUM)
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
		zoom = 0.90;
	else
		zoom = 1.10;
	i = 1.0 / zoom;
	ptr->min.x = mouse.x + ((ptr->min.x - mouse.x) * i);
	ptr->min.y = mouse.y + ((ptr->min.y - mouse.y) * i);
	ptr->max.x = mouse.x + ((ptr->max.x - mouse.x) * i);
	ptr->max.y = mouse.y + ((ptr->max.y - mouse.y) * i);
	//draw(ptr);
	thread(ptr);
	return (0);
}

void	move_img(int key, t_ptr *ptr)
{
	t_complex	delta;

	delta.x = ptr->max.x - ptr->min.x;
	delta.y = ptr->max.y - ptr->min.y;
	if (key == RIGHT)
	{
		ptr->min.x -= delta.x * 0.01;
		ptr->max.x -= delta.x * 0.01;
	}
	else if (key == LEFT)
	{
		ptr->min.x += delta.x * 0.01;
		ptr->max.x += delta.x * 0.01;
	}
	else if (key == DOWN)
	{
		ptr->min.y += delta.y * 0.01;
		ptr->max.y += delta.y * 0.01;
	}
	else if (key == UP)
	{
		ptr->min.y -= delta.y * 0.01;
		ptr->max.y -= delta.y * 0.01;
	}
	//draw(ptr);
	thread(ptr);
}

int		key_press(int key, t_ptr *ptr)
{
	if (key == ESC)
		exit(0);
	if (key == Q_BUTTON || key == W_BUTTON ||
		key == PLUS_NUM || key == MINUS_NUM)
	{
		ft_bzero(ptr->data_addr, IMG_W * IMG_H * (ptr->bits_per_pixel / 8));
		ptr->max_iteration += change_max_iteration(key, ptr);
		//draw(ptr);
		thread(ptr);
	}
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move_img(key, ptr);
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

int 	mouse_release(int key, int x, int y, t_ptr *ptr)
{
	if (key == MOUSE_LEFT && x >= 0 && y >= 0)
		ptr->mouse_left = NOT_PRESSED;
	return (0);
}

int 	mouse_move(int x, int y, t_ptr *ptr)
{
	t_complex	delta;
	int			dx;
	int			dy;

	delta.x = ptr->max.x - ptr->min.x;
	delta.y = ptr->max.y - ptr->min.y;
	//
	ptr->mouse->prev_x = ptr->mouse->curr_x;
	ptr->mouse->prev_y = ptr->mouse->curr_y;
	ptr->mouse->curr_x = x;
	ptr->mouse->curr_y = y;
	//
	dx = ptr->mouse->curr_x - ptr->mouse->prev_x;
	dy = ptr->mouse->curr_y - ptr->mouse->prev_y;
	if (ptr->mouse_left == IS_PRESSED)
	{
		ptr->min.x += dx <= 0 ? delta.x * 0.01 : delta.x * (-0.01);
		ptr->max.x += dx <= 0 ? delta.x * 0.01 : delta.x * (-0.01);
		ptr->min.y += dy >= 0 ? delta.y * 0.01 : delta.y * (-0.01);
		ptr->max.y += dy >= 0 ? delta.y * 0.01 : delta.y * (-0.01);
	}
	//draw(ptr);
	thread(ptr);
	return (0);
}