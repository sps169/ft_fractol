/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:04:22 by sperez-s          #+#    #+#             */
/*   Updated: 2022/12/19 13:05:56 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	zoom(double zoom, int x, int y, t_vars *vars)
{
	t_cn	pter;
	double	intpol_val;

	vars->screen.zoom *= zoom;
	pter.r = vars->frame.min.r + ((vars->frame.max.r - vars->frame.min.r)
			/ (double)vars->screen.size_x) * (double)x;
	pter.i = vars->frame.min.i + ((vars->frame.max.i - vars->frame.min.i)
			/ (double)vars->screen.size_y) * (double)y;
	intpol_val = 1.0 / zoom;
	vars->frame.min.r = interpolate(pter.r, vars->frame.min.r, intpol_val);
	vars->frame.min.i = interpolate(pter.i, vars->frame.min.i, intpol_val);
	vars->frame.max.r = interpolate(pter.r, vars->frame.max.r, intpol_val);
	vars->frame.max.i = interpolate(pter.i, vars->frame.max.i, intpol_val);
}
