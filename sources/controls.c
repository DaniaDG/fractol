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
	if (key == 13)
		return (ptr->max_iteration == 1 ? 0 : -1);
	return (1);
}

int		change_zoom(int key, t_ptr *ptr)
{
	if (key == 0)
	{
		ptr->h += ptr->h == IMG_H ? 0 : -10;
		ptr->w += ptr->w == IMG_W ? 0 : -10;
	}
	else
	{
		ptr->h += 10;
		ptr->w += 10;
	}
	return (0);
}

int		key_press(int key, t_ptr *ptr)
{
	if (key == 53)
		exit(0);
	if (key == 12 || key == 13)
		ptr->max_iteration += change_max_iteration(key, ptr);
	if (key == 0 || key == 1)
		change_zoom(key, ptr);
	//printf("zoom = %f\n", ptr->zoom);
	draw(ptr);
	return (0);
}

/*int		mouse_press(int key, t_ptr *ptr)
{
	if (key == 4 || key == 5)
		ptr->zoom += change_zoom(key, ptr);
	draw(ptr);
	return (0);
}*/
