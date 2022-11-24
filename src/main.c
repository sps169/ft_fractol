/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:21:16 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/24 13:58:06 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int main(void)
{
	t_vars		vars;
	t_mlx_win	mlx_win;
	t_screen	screen;
	t_cn		center;
	
	screen.size_x = 1920;
	screen.size_y = 1080;
	screen.jumps_x = 0;
	screen.jumps_y = 0;
	screen.zoom = 1;
	center.r = -1;
	center.i = 0;
	mlx_win.mlx = mlx_init();
	mlx_win.win = mlx_new_window(mlx_win.mlx, screen.size_x, screen.size_y, "fractol");
	vars.center = center;
	vars.screen = screen;
	vars.mlx_win = mlx_win;
	vars.m_pos_x = (int)(1920 / 2);
	vars.m_pos_y = (int)(1080 / 2);
	// mlx_hook(vars.mlx_win.win, 6, (1L<<6), mouse_move_hook, &vars);
	mlx_mouse_hook(vars.mlx_win.win, scroll_hook, &vars);
	paint(vars, calculate_color, mandelbrot_escape_iterations);
	mlx_loop(mlx_win.mlx);
}
