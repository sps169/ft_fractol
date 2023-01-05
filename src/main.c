/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:21:16 by sperez-s          #+#    #+#             */
/*   Updated: 2023/01/05 19:26:53 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int main(void)
{
	t_vars		vars;
	t_mlx_win	mlx_win;

	initial_position(&vars);
	mlx_win.mlx = mlx_init();
	mlx_win.win = mlx_new_window(mlx_win.mlx, vars.screen.size_x, vars.screen.size_y, "fractol");
	vars.mlx_win = mlx_win;
	// mlx_hook(vars.mlx_win.win, 6, (1L<<6), mouse_move_hook, &vars);
	mlx_mouse_hook(vars.mlx_win.win, scroll_hook, &vars);
	mlx_key_hook(vars.mlx_win.win, keyboard_hook, &vars);
	mlx_hook(vars.mlx_win.win, 17, (1L << 0), close_fractol, &vars);
	paint(vars, calculate_color, julia_escape_iterations);
	mlx_loop(mlx_win.mlx);
}
