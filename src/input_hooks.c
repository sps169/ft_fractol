/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:32:55 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/24 13:58:09 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	scroll_hook(int m_code, t_vars vars)
{
	printf("Pos: %i, %i\n", vars.m_pos_x, vars.m_pos_y);
	if (vars.m_pos_x >= 0 && vars.m_pos_y >= 0)
	{
		if (m_code == 4 || m_code == 5)
		{
			if (m_code == 4)
				vars.screen.zoom = vars.screen.zoom++;
			else if (m_code == 5)
				vars.screen.zoom = vars.screen.zoom / 2;
			vars.center.r = vars.center.r + (vars.m_pos_x - vars.screen.size_x / 2) * (0.003 / vars.screen.zoom);
			vars.center.i = vars.center.i + (vars.m_pos_y - vars.screen.size_y / 2) * (0.003 / vars.screen.zoom);
		}
		paint(vars, calculate_color, mandelbrot_escape_iterations);
	}
	return (0);
}

int	mouse_move_hook(int x, int y, t_vars vars)
{
	printf("Pos: %i %i\n", x, y);
	vars.m_pos_x = x;
	vars.m_pos_y = y;
	return (0);
}
