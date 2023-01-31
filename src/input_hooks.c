/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:32:55 by sperez-s          #+#    #+#             */
/*   Updated: 2023/01/31 12:33:50 by sperez-s         ###   ########.fr       */
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

int	keyboard_hook(int k_code, t_vars *vars)
{
	if (k_code == 126)
		jump(NORTH, vars);
	else if(k_code == 125)
		jump(SOUTH, vars);
	else if (k_code == 123)
		jump(WEST, vars);
	else if (k_code == 124)
		jump(EAST, vars);
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
		initial_position(vars);
		paint(*vars, calculate_color, vars->maths_function);
	}
	else if (k_code == 8)
	{
		if (vars->color >= 3)
			vars->color = 1;
		else
			vars->color++;
		paint(*vars, calculate_color, vars->maths_function);
	}
	return (0);
}

//126 up
//125 down
//123 left
//124 right
//53 ESC
//46 M
//38 J
//6 Z
//7 X
//8 C
//15 R
//14 E
//40 K
