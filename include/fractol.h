/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:27:08 by sperez-s          #+#    #+#             */
/*   Updated: 2022/11/22 11:56:27 by sperez-s         ###   ########.fr       */
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

unsigned int	calculate_color(int it, int max_it);

unsigned int	hsv_to_rgb_int(double h, double s, double v);

unsigned int	rgb_to_int(unsigned int r, unsigned int g, unsigned int b);

#endif
