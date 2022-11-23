/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:44:21 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/23 12:15:37 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	paint(t_cn center, t_screen screen, t_mlx_win mlx,
	unsigned int (*coloring)(int, int), int (*math)(t_cn, int))
{
	unsigned int	i;
	unsigned int	j;
	t_cn			curr_n;
	t_cn			initial_n;

	initial_n.r = center.r + screen.jumps_x * (1 / screen.zoom) - (screen.size_x / 2) * (0.003 / screen.zoom);
	initial_n.i = center.i + screen.jumps_y * (1 / screen.zoom) - (screen.size_y / 2) * (0.003 / screen.zoom);
	i = 0;
	j = 0;
	while (i < screen.size_x)
	{
		while (j < screen.size_y)
		{
			printf("(%i, %i)[r: %.2f,i: %.2f]", i, j, curr_n.r, curr_n.i);
			curr_n.r = initial_n.r + ((0.003 / screen.zoom) * i);
			curr_n.i = initial_n.i + ((0.003 / screen.zoom) * j);
			mlx_pixel_put(mlx.mlx, mlx.win, i, j, coloring(math(curr_n, 100), 100));
			j++;
		}
		j = 0;
		i++;
	}
}
