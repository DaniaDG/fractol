/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:46:07 by bsausage          #+#    #+#             */
/*   Updated: 2019/10/22 09:07:49 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_mlx(t_ptr *ptr)
{
	if (!(ptr->mlx = mlx_init()))
		error("mlx init error");
	if (!(ptr->win = mlx_new_window(ptr->mlx, WIDTH, HEIGHT,
			"Fractol by bsausage")))
		error("windows init error");
	if (!(ptr->img = mlx_new_image(ptr->mlx, IMG_W, IMG_H)))
		error("image init error");
	ptr->data_addr = mlx_get_data_addr(ptr->img, &(ptr->bits_per_pixel),
										&(ptr->size_line), &(ptr->endian));
}

t_ptr		*init_ptr(void)
{
	t_ptr	*ptr;

	if (!(ptr = (t_ptr *)malloc(sizeof(t_ptr))))
		error("init error");
	init_mlx(ptr);
	if (!(ptr->mouse = (t_mouse *)malloc(sizeof(t_mouse))))
		error("init mouse error");
	ptr->min.x = -2.0;
	ptr->max.x = 2.0;
	ptr->min.y = -2.0;
	ptr->max.y = ptr->min.x + (ptr->max.x - ptr->min.x) * IMG_H / IMG_W;
	ptr->k.x = -0.4;
	ptr->k.y = 0.6;
	ptr->space_button = NOT_PRESSED;
	ptr->mouse_left = NOT_PRESSED;
	ptr->max_iteration = 50;
	ptr->color_f = &get_color2;
	return (ptr);
}
