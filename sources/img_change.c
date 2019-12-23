/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 19:00:51 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/11 19:00:52 by bsausage         ###   ########.fr       */
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
	thread(ptr);
	return (0);
}

int		redraw(t_ptr *ptr)
{
	ptr->min.x = -2.0;
	ptr->max.x = 2.0;
	ptr->min.y = -2.0;
	ptr->max.y = ptr->min.x + (ptr->max.x - ptr->min.x) * IMG_H / IMG_W;
	ptr->max_iteration = 50;
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
	thread(ptr);
}

void	move_img_by_mouse(int x, int y, t_ptr *ptr)
{
	t_complex	delta;
	t_complex	d;

	delta.x = ptr->max.x - ptr->min.x;
	delta.y = ptr->max.y - ptr->min.y;
	ptr->mouse->prev_x = ptr->mouse->curr_x;
	ptr->mouse->prev_y = ptr->mouse->curr_y;
	ptr->mouse->curr_x = x;
	ptr->mouse->curr_y = y;
	d.x = (x - ptr->mouse->prev_x) * delta.x / (IMG_W - 1);
	d.y = (y - ptr->mouse->prev_y) * delta.y / (IMG_H - 1);
	ptr->min.x -= d.x;
	ptr->min.y += d.y;
	ptr->max.x -= d.x;
	ptr->max.y += d.y;
	thread(ptr);
}
