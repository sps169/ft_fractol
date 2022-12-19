/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:32:55 by sperez-s          #+#    #+#             */
/*   Updated: 2022/12/19 13:06:41 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	scroll_hook(int m_code, int x, int y, t_vars *vars)
{
	if (x >= 0 && y >= 0 && x < (int)vars->screen.size_x
		&& y < (int)vars->screen.size_y)
	{
		if (m_code == 4 || m_code == 5)
		{
			if (m_code == 4)
				zoom(0.5, x, y, vars);
			else if (m_code == 5)
				zoom(1.5, x, y, vars);
			paint(*vars, calculate_color, mandelbrot_escape_iterations);
		}
	}
	return (0);
}
