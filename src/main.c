/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:21:16 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/22 12:34:21 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(void)
{
	void	*mlx;
	void	*win;
	int		i;
	int		j;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 200, 200, "Hello world!");
	i = 0;
	j = 0;
	while (i < 20)
	{
		while(j < 20)
		{
			mlx_pixel_put(mlx, win, 90 + i, 90 + j, calculate_color(900, 1000));
			j++;
		}
		j = 0;
		i++;
	}
	mlx_loop(mlx);
}
