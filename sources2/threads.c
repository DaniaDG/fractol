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

/*int			thread(t_ptr *ptr)
{
	int			result;
	pthread_t	thread1;
	pthread_t	thread2;
	void		*status1;
	void		*status2;
	pthread_t	thread3;
	pthread_t	thread4;
	void		*status3;
	void		*status4;

	ft_bzero(ptr->data_addr, IMG_W * IMG_H * (ptr->bits_per_pixel / 8));
	result = pthread_create(&thread1, NULL, draw1, (void*)ptr);
	if (result != 0)
	{
		perror("Creating thread");
		exit(ERROR_CREATE_THREAD);
	}
	result = pthread_create(&thread2, NULL, draw2, (void*)ptr);
	if (result != 0)
	{
		perror("Creating thread");
		exit(ERROR_CREATE_THREAD);
	}
	result = pthread_create(&thread3, NULL, draw3, (void*)ptr);
	if (result != 0)
	{
		perror("Creating thread");
		exit(ERROR_CREATE_THREAD);
	}
	result = pthread_create(&thread4, NULL, draw4, (void*)ptr);
	if (result != 0)
	{
		perror("Creating thread");
		exit(ERROR_CREATE_THREAD);
	}
	//
	result = pthread_join(thread1, &status1);
	if (result != 0)
	{
		perror("Joining thread");
		exit(ERROR_JOIN_THREAD);
	}
	result = pthread_join(thread2, &status2);
	if (result != 0)
	{
		perror("Joining thread");
		exit(ERROR_JOIN_THREAD);
	}
	result = pthread_join(thread3, &status3);
	if (result != 0)
	{
		perror("Joining thread");
		exit(ERROR_JOIN_THREAD);
	}
	result = pthread_join(thread4, &status4);
	if (result != 0)
	{
		perror("Joining thread");
		exit(ERROR_JOIN_THREAD);
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	return (0);
}*/

int		thread(t_ptr *ptr)
{
	int			result;
	pthread_t	threads[MAXTHREADS];
	void		*status[MAXTHREADS];
	int			i;
	t_ptr		tmp[MAXTHREADS];

	ft_bzero(ptr->data_addr, IMG_W * IMG_H * (ptr->bits_per_pixel / 8));
	i = 0;
	while (i < MAXTHREADS)
	{
		tmp[i] = *ptr;
		//tmp[i].mouse_left = NOT_PRESSED;
		tmp[i].y_begin = i * (IMG_H / MAXTHREADS);
		tmp[i].y_end = tmp[i].y_begin + IMG_H / MAXTHREADS;
		result = pthread_create(&threads[i], NULL, draw2, &tmp[i]);
		if (result != 0)
		{
			perror("Creating thread");
			exit(ERROR_CREATE_THREAD);
		}
		i++;
	}
	//
	i = 0;
	while (i < MAXTHREADS)
	{
		result = pthread_join(threads[i], &status[i]);
		if (result != 0)
		{
			perror("Joining thread");
			exit(ERROR_JOIN_THREAD);
		}
		i++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0);
	return (0);
}
