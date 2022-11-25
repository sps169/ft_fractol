/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:44:21 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/25 19:05:55 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <unistd.h>

void	paint(t_vars vars, unsigned int (*coloring)(int, int), int (*math)(t_cn, int))
{
	unsigned int	i;
	unsigned int	j;
	t_cn			curr_n;
	t_cn			initial_n;

	
	initial_n.r = vars.center.r + vars.screen.jumps_x * (0.003 / vars.screen.zoom) - (vars.screen.size_x / 2) * (0.003 / vars.screen.zoom);
	initial_n.i = vars.center.i + vars.screen.jumps_y * (0.003 / vars.screen.zoom) - (vars.screen.size_y / 2) * (0.003 / vars.screen.zoom);
	curr_n.r = initial_n.r;
	curr_n.i = initial_n.i;
	i = 0;
	j = 0;
	while (i < vars.screen.size_x)
	{
		while (j < vars.screen.size_y)
		{
			curr_n.r = initial_n.r + vars.screen.jumps_x * (0.003 / vars.screen.zoom) + ((0.003 / vars.screen.zoom) * (double)i);
			curr_n.i = initial_n.i + vars.screen.jumps_y * (0.003 / vars.screen.zoom) + ((0.003 / vars.screen.zoom) * (double)j);
			mlx_pixel_put(vars.mlx_win.mlx, vars.mlx_win.win, i, j, coloring(math(curr_n, 100), 100));
			j++;
		}
		j = 0;
		i++;
	}
}

