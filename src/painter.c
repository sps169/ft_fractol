/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:44:21 by sperez-s          #+#    #+#             */
/*   Updated: 2023/01/31 12:19:08 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	paint(t_vars vars, unsigned int (*coloring)(int, int, t_vars),
				int (*math)(t_cn, t_cn, int))
{
	unsigned int	i;
	unsigned int	j;
	t_cn			curr_n;

	
	curr_n.r = vars.frame.min.r;
	curr_n.i = vars.frame.min.i;
	i = 0;
	while (i < vars.screen.size_x)
	{
		j = 0;
		while (j <= vars.screen.size_y)
		{
			curr_n.r = vars.frame.min.r + ((vars.frame.max.r - vars.frame.min.r)
					/ (double)vars.screen.size_x) * (double)i;
			curr_n.i = vars.frame.min.i + ((vars.frame.max.i - vars.frame.min.i)
					/ (double)vars.screen.size_y) * (double)j;
			mlx_pixel_put(vars.mlx_win.mlx, vars.mlx_win.win, i, j,
				coloring(math(curr_n, vars.c, vars.max_it), vars.max_it, vars));
			j++;
		}
		i++;
	}
}
