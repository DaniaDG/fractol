/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:46:07 by bsausage          #+#    #+#             */
/*   Updated: 2019/10/22 09:07:49 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_color_formula(t_ptr *ptr)
{
	if (ptr->color_f == &get_color1)
	{
		ptr->color_f = &get_color2;
		thread(ptr);
		return ;
	}
	ptr->color_f = &get_color1;
	thread(ptr);
}

int		turn_off(void *param)
{
	(void)param;
	exit(0);
}

void	error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(1);
}

void	hooks(t_ptr *ptr)
{
	mlx_hook(ptr->win, 2, 0, key_press, ptr);
	mlx_hook(ptr->win, 4, 0, mouse_press, ptr);
	mlx_hook(ptr->win, 5, 0, mouse_release, ptr);
	mlx_hook(ptr->win, 6, 0, mouse_move, ptr);
	mlx_hook(ptr->win, 17, 0, turn_off, ptr);
	mlx_loop(ptr->mlx);
}
