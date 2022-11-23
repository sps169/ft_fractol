/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:21:16 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/23 12:12:35 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
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
	paint(center, screen, mlx_win, calculate_color, mandelbrot_escape_iterations);
	mlx_loop(mlx_win.mlx);
}
