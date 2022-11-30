/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:32:55 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/30 13:37:46 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	scroll_hook(int m_code, int x, int y, t_vars *vars)
{
	double	prev_zoom;
	t_cn	pointer;
	double	distance;
	double	angle;

	prev_zoom = vars->screen.zoom;
	if (x >= 0 && y >= 0)
	{
		vars->m_pos_x = x;
		vars->m_pos_y = y;
		if (m_code == 4 || m_code == 5)
		{
			pointer.r = 0.003 / prev_zoom * ((double)vars->m_pos_x - (double)vars->screen.size_x / 2.0) + vars->center.r;
			pointer.i = 0.003 / prev_zoom * ((double)vars->m_pos_y - (double)vars->screen.size_x / 2.0) + vars->center.i;
			
			distance = sqrt(pow(fabs(vars->center.r - pointer.r), 2.0) + pow(fabs(vars->center.i - pointer.i), 2.0));
			angle = atan((vars->center.i - pointer.i)/(vars->center.r - pointer.r));
			printf("Distance: %f\nPointer: (%f, %f)\nCenter: (%f, %f)\n", distance, pointer.r, pointer.i, vars->center.r, vars->center.i);
			
			if (m_code == 4)
			{
				vars->screen.zoom = vars->screen.zoom / 1.1;
				distance *= sqrt(2) * 1.1;
			}
			else if (m_code == 5)
			{
				vars->screen.zoom = vars->screen.zoom * 1.1;
				distance /= sqrt(2) * 1.1;
			}
			vars->center.r = (vars->center.r - pointer.r) * distance * cos(angle);
			vars->center.i = (vars->center.i - pointer.i) * distance * sin(angle);
			printf("NewCenter: (%f, %f)\n", vars->center.r, vars->center.i);
			paint(*vars, calculate_color, mandelbrot_escape_iterations);
		}
	}
	return (0);
}

int	mouse_move_hook(int x, int y, t_vars *vars)
{
	vars->m_pos_x = x;
	vars->m_pos_y = y;
	return (0);
}
