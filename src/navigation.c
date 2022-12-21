/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:04:22 by sperez-s          #+#    #+#             */
/*   Updated: 2022/12/21 11:12:02 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

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
	paint(*vars, calculate_color, mandelbrot_escape_iterations);
}

void	jump(int direction, t_vars *vars)
{
	double	size;
	
	if (direction == NORTH || direction == SOUTH)
	{
		size = fabs(vars->frame.min.i - vars->frame.max.i);
		if (direction == NORTH)
			size *= -1;
		vars->frame.min.i += size / 4;
		vars->frame.max.i += size / 4;
	}
	else if (direction == EAST || direction == WEST)
	{
		size = fabs(vars->frame.min.r - vars->frame.max.r);
		if (direction == WEST)
			size *= -1;
		vars->frame.min.r += size / 4;
		vars->frame.max.r += size / 4;
	}
	paint(*vars, calculate_color, mandelbrot_escape_iterations);
}

void	initial_position(t_vars *vars)
{
	t_screen	screen;
	t_frame		frame;
	t_cn		min;
	t_cn		max;

	screen.size_x = 1920;
	screen.size_y = 1080;
	screen.zoom = 1;
	min.r = -3.8;
	max.i = 1.8;
	max.r = 2.6;
	min.i = -1.8;
	frame.min = min;
	frame.max = max;
	vars->max_it = 50;
	vars->screen = screen;
	vars->frame = frame;
}
