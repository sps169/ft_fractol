/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:27:08 by sperez-s          #+#    #+#             */
/*   Updated: 2023/01/05 19:24:56 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <mlx.h>

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

struct	s_cn
{
	double	r;
	double	i;
};
typedef struct s_cn	t_cn;

struct	s_screen
{
	double			zoom;
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

struct s_frame
{
	t_cn	min;
	t_cn	max;
};
typedef struct s_frame	t_frame;

struct s_vars
{
	struct s_mlx_win	mlx_win;
	struct s_screen		screen;
	struct s_frame		frame;
	int					max_it;
	int					color;
};
typedef struct s_vars	t_vars;

unsigned int	calculate_color(int it, int max_it, t_vars vars);

void			paint(t_vars vars, unsigned int (*coloring)(int, int, t_vars), int (*math)(t_cn, int));

int				mandelbrot_escape_iterations(t_cn c, int max_it);

int				julia_escape_iterations(t_cn c, int max_it);

int				scroll_hook(int m_code, int x, int y, t_vars *vars);

void			zoom(double zoom, int x, int y, t_vars *vars);

int				keyboard_hook(int k_code, t_vars *vars);

void			jump(int direction, t_vars *vars);

void			initial_position(t_vars *vars);

int				close_fractol(t_vars *vars);

#endif
