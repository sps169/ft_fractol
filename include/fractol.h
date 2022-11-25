/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:27:08 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/25 18:19:08 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

struct	s_cn
{
	double	r;
	double	i;
};
typedef struct s_cn	t_cn;

struct	s_screen
{
	double			zoom;
	double			jumps_x;
	double			jumps_y;
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

struct s_vars
{
	struct s_mlx_win	mlx_win;
	struct s_screen		screen;
	struct s_cn			center;
	int					m_pos_x;
	int					m_pos_y;
};
typedef struct s_vars	t_vars;

unsigned int	calculate_color(int it, int max_it);

void			paint(t_vars vars, unsigned int (*coloring)(int, int), int (*math)(t_cn, int));

int				mandelbrot_escape_iterations(t_cn c, int max_it);

int				scroll_hook(int m_code, int x, int y, t_vars *vars);

int				mouse_move_hook(int x, int y, t_vars *vars);

#endif
