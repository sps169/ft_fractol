/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:32:55 by sperez-s          #+#    #+#             */
/*   Updated: 2023/02/09 11:49:04 by sperez-s         ###   ########.fr       */
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
		}
	}
	return (0);
}

static void	jump_hooks(int k_code, t_vars *vars)
{
	if (k_code == 126)
		jump(NORTH, vars);
	else if (k_code == 125)
		jump(SOUTH, vars);
	else if (k_code == 123)
		jump(WEST, vars);
	else if (k_code == 124)
		jump(EAST, vars);
}

static void	change_color(t_vars *vars)
{
	if (vars->color >= 3)
		vars->color = 1;
	else
		vars->color++;
	paint(*vars, calculate_color, vars->maths_function);
}

int	keyboard_hook(int k_code, t_vars *vars)
{
	if (k_code >= 123 && k_code <= 126)
		jump_hooks(k_code, vars);
	else if (k_code == 53)
		close_fractol(vars);
	else if (k_code == 6 && vars->max_it >= 35)
	{
		vars->max_it -= 25;
		paint(*vars, calculate_color, vars->maths_function);
	}
	else if (k_code == 7 && vars->max_it <= 10000)
	{
		vars->max_it += 25;
		paint(*vars, calculate_color, vars->maths_function);
	}
	else if (k_code == 15)
	{
		reset_position(vars);
		paint(*vars, calculate_color, vars->maths_function);
	}
	else if (k_code == 8)
		change_color(vars);
	return (0);
}
