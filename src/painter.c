/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:44:21 by sperez-s          #+#    #+#             */
/*   Updated: 2022/12/19 13:04:24 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <unistd.h>

void	paint(t_vars vars, unsigned int (*coloring)(int, int),
				int (*math)(t_cn, int))
{
	unsigned int	i;
	unsigned int	j;
	t_cn			curr_n;

	curr_n.r = vars.frame.min.r;
	curr_n.i = vars.frame.min.i;
	i = 1;
	while (i <= vars.screen.size_x)
	{
		j = 1;
		while (j <= vars.screen.size_y)
		{
			curr_n.r = vars.frame.min.r + ((vars.frame.max.r - vars.frame.min.r)
					/ (double)vars.screen.size_x) * (double)i;
			curr_n.i = vars.frame.min.i + ((vars.frame.max.i - vars.frame.min.i)
					/ (double)vars.screen.size_y) * (double)j;
			mlx_pixel_put(vars.mlx_win.mlx, vars.mlx_win.win, i, j,
				coloring(math(curr_n, vars.max_it), vars.max_it));
			j++;
		}
		i++;
	}
}
