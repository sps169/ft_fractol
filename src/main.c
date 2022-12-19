/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:21:16 by sperez-s          #+#    #+#             */
/*   Updated: 2022/12/19 12:51:03 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int main(void)
{
	t_vars		vars;
	t_mlx_win	mlx_win;
	t_screen	screen;
	t_frame		frame;
	t_cn		min;
	t_cn		max;
	
	screen.size_x = 1920;
	screen.size_y = 1080;
	screen.jumps_x = 0;
	screen.jumps_y = 0;
	screen.zoom = 1;
	min.r = -3.8;
	max.i = 1.8;
	max.r = 2.6;
	min.i = -1.8;
	frame.min = min;
	frame.max = max;
	mlx_win.mlx = mlx_init();
	mlx_win.win = mlx_new_window(mlx_win.mlx, screen.size_x, screen.size_y, "fractol");
	vars.screen = screen;
	vars.frame = frame;
	vars.mlx_win = mlx_win;
	vars.max_it = 50;
	// mlx_hook(vars.mlx_win.win, 6, (1L<<6), mouse_move_hook, &vars);
	mlx_mouse_hook(vars.mlx_win.win, scroll_hook, &vars);
	paint(vars, calculate_color, mandelbrot_escape_iterations);
	mlx_loop(mlx_win.mlx);
}
