/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsausage <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:46:07 by bsausage          #+#    #+#             */
/*   Updated: 2019/10/22 09:07:49 by bsausage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		(*get_formula(char *name)) (int x, int y, t_ptr *ptr)
{
	if (ft_strequ(name, "Mandelbrot"))
		return (&mandelbrot);
	if (ft_strequ(name, "Julia"))
		return (&julia);
	if (ft_strequ(name, "Ship"))
		return (&burning_ship);
	return (0);
}

int				main(int argc, char **argv)
{
	t_ptr		*ptr;

	errno = 0;
	if (argc == 1)
		error("missing arguments");
	if (argc > 2)
		error("too many arguments");
	ptr = init_ptr();
	if (ft_strequ(argv[1], "Julia"))
		ptr->is_julia = 1;
	if (!(ptr->formula = get_formula(argv[1])))
		error("fractal name error");
	thread(ptr);
	hooks(ptr);
	return (0);
}
