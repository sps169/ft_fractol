/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:32:55 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/25 19:52:28 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	scroll_hook(int m_code, int x, int y, t_vars *vars)
{
	if (x >= 0 && y >= 0)
	{
		vars->m_pos_x = x;
		vars->m_pos_y = y;
		if (m_code == 4 || m_code == 5)
		{
			if (m_code == 4)
				vars->screen.zoom = vars->screen.zoom / 1.1;
			else if (m_code == 5)
				vars->screen.zoom = vars->screen.zoom * 1.1;
			vars->center.r += ((double)vars->m_pos_x - ((double)vars->screen.size_x / 2.0)) * (0.003 / vars->screen.zoom);
			vars->center.i += ((double)vars->m_pos_y - ((double)vars->screen.size_y / 2.0)) * (0.003 / vars->screen.zoom);
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
