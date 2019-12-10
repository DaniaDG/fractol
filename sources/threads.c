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

int		threads(t_ptr *ptr)
{
	int			result;
	pthread_t	threads[MAXTHREADS];
	void		*status[MAXTHREADS];
	int			i;
	t_ptr		tmp[MAXTHREADS];

	i = 0;
	while (i < MAXTHREADS)
	{
		tmp[i] = *ptr;
		tmp[i].y = i * 100;
		tmp[i].max.y = tmp[i].y + 100;
		result = pthread_create(&threads[i], NULL, draw, &tmp[i]);
		if (result)
			perror("Creating thread");
		i++;
	}
	//
	i = 0;
	while (i < MAXTHREADS)
	{
		result = pthread_join(threads[i], &status[i]);
		if (result)
			perror("Joining thread");
		i++;
	}
	return (0);
}
