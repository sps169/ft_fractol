/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_maths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:57:29 by sperez-s          #+#    #+#             */
/*   Updated: 2023/01/31 12:41:23 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_escape_iterations(t_cn zo, t_cn c, int max_it)
{
	t_cn	z;
	double	aux_i;
	int		it;

	z = zo;
	z.r += c.r;
	z.i += c.i;
	it = 0;
	aux_i = 0;
	while (it < max_it && fabs(z.r * z.r + z.i * z.i) < 4)
	{
		aux_i = z.i * z.i;
		z.i = 2 * z.r * z.i + zo.i;
		z.r = z.r * z.r - aux_i + zo.r;
		it++;
	}
	return (it);
}

int	julia_escape_iterations(t_cn zo, t_cn c, int max_it)
{
	t_cn	z;
	double	aux_i;
	int		it;

	z = zo;
	z.r += c.r;
	z.i += c.i;
	it = 0;
	aux_i = 0;
	while (it < max_it && fabs(z.r * z.r + z.i * z.i) < 4)
	{
		aux_i = z.i * z.i;
		z.i = 2 * z.r * z.i + c.i;
		z.r = z.r * z.r - aux_i + c.r;
		it++;
	}
	return (it);
}
