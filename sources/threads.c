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
#include <pthread.h>

int		thread(t_ptr *ptr)
{
	int			result;
	pthread_t	threads[MAXTHREADS];
	void		*status[MAXTHREADS];
	int			i;
	t_ptr		tmp[MAXTHREADS];

	ft_bzero(ptr->data_addr, IMG_W * IMG_H * (ptr->bits_per_pixel / 8));
	i = -1;
	while (++i < MAXTHREADS)
	{
		tmp[i] = *ptr;
		tmp[i].y_begin = i * (IMG_H / MAXTHREADS);
		tmp[i].y_end = tmp[i].y_begin + IMG_H / MAXTHREADS;
		if ((result = pthread_create(&threads[i], NULL, draw, &tmp[i])))
			error("Creating thread");
	}
	i = -1;
	while (++i < MAXTHREADS)
	{
		if ((result = pthread_join(threads[i], &status[i])))
			perror("Joining thread");
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	draw_help(ptr);
	return (0);
}
