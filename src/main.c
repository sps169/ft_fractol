/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 12:21:16 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/17 13:02:36 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

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
	while (i < 10)
	{
		while(j < 10)
		{
			mlx_pixel_put(mlx, win, 95 + i, 95 + j, 1000);
			j++;
		}
		j = 0;
		i++;
	}
	mlx_loop(mlx);
}
