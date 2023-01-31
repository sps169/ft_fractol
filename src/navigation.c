/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:04:22 by sperez-s          #+#    #+#             */
/*   Updated: 2023/01/31 12:39:58 by sperez-s         ###   ########.fr       */
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
	t_cn		c;

	screen.size_x = 1920;
	screen.size_y = 1080;
	screen.zoom = 1;
	c.r = 0.3;
	c.i = 0.2;
	min.r = -3.8 - c.r;
	max.i = 1.8 - c.i;
	max.r = 2.6 - c.r;
	min.i = -1.8 - c.i;
	frame.min = min;
	frame.max = max;
	// c.r = 0;
	// c.i = 0;
	vars->c = c;
	vars->max_it = 50;
	vars->screen = screen;
	vars->frame = frame;
	vars->color = 1;
	vars->maths_function = &mandelbrot_escape_iterations;
}

int	close_fractol(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_win.mlx, vars->mlx_win.win);
	exit(EXIT_SUCCESS);
}
