/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 16:08:15 by bsausage          #+#    #+#             */
/*   Updated: 2019/12/14 16:08:17 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_help(t_ptr *ptr)
{
	mlx_string_put(ptr->mlx, ptr->win, 10, 830, SILVER,
		"Reset          - R");
	mlx_string_put(ptr->mlx, ptr->win, 10, 850, SILVER,
		"Next image     - N");
	mlx_string_put(ptr->mlx, ptr->win, 10, 870, SILVER,
		"Move           - Arrows");
	mlx_string_put(ptr->mlx, ptr->win, 10, 890, SILVER,
		"Zoom           - Scroll");
	mlx_string_put(ptr->mlx, ptr->win, 10, 910, SILVER,
		"Iterations     - +/-");
	mlx_string_put(ptr->mlx, ptr->win, 10, 930, SILVER,
		"Color Change   - C/Num_Enter");
	mlx_string_put(ptr->mlx, ptr->win, 10, 950, SILVER,
		"Julia Constant - Mouse");
	mlx_string_put(ptr->mlx, ptr->win, 10, 970, SILVER,
		"Julia Pause    - Space");
}
