/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_vars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:20:40 by sperez-s          #+#    #+#             */
/*   Updated: 2023/02/09 11:41:29 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initial_position(char fractal, t_vars *vars)
{
	t_screen	screen;
	t_frame		frame;
	t_cn		min;
	t_cn		max;

	vars->fractal = fractal;
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
	vars->color = 1;
	if (fractal == JULIA)
		vars->maths_function = &julia_escape_iterations;
	else if (fractal == EXTRA)
		vars->maths_function = &burning_ship_escape_iterations;
	else
		vars->maths_function = &mandelbrot_escape_iterations;
}

void	reset_position(t_vars *vars)
{
	vars->screen.zoom = 1;
	vars->frame.min.r = -3.8;
	vars->frame.max.i = 1.8;
	vars->frame.max.r = 2.6;
	vars->frame.min.i = -1.8;
	vars->max_it = 50;
	vars->color = 1;
}
