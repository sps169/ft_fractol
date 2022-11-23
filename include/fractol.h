/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:27:08 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/23 11:32:26 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

struct	s_pixel {
	int	x;
	int	y;
	int	color;
};
typedef struct s_pixel	t_pixel;

struct	s_cn
{
	double	r;
	double	i;
};
typedef struct s_cn	t_cn;

struct	s_screen
{
	unsigned int	zoom;
	int				jumps_x;
	int				jumps_y;
	unsigned int	size_x;
	unsigned int	size_y;
};
typedef struct s_screen	t_screen;

struct s_mlx_win
{
	void	*mlx;
	void	*win;
};
typedef struct s_mlx_win	t_mlx_win;

unsigned int	calculate_color(int it, int max_it);

void			paint(t_cn center, t_screen screen, t_mlx_win mlx,
					unsigned int (*coloring)(int, int), int (*math)(t_cn, int));

int				mandelbrot_escape_iterations(t_cn c, int max_it);

#endif
