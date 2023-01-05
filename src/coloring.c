/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:24:16 by sperez-s          #+#    #+#             */
/*   Updated: 2023/01/04 10:10:02 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static unsigned int	rgb_to_int(unsigned int r, unsigned int g, unsigned int b)
{
	unsigned int	rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

static unsigned int	hsv_to_rgb_int(double h, double s, double v)
{
	double	c;
	double	x;
	double	m;

	c = v * s;
	x = c * (1 - fabs(fmod(h / 60, 2) - 1));
	m = v - c;
	if (0 <= h && h < 60)
		return (rgb_to_int(round((c + m) * 255),
				round((x + m) * 255), round((0 + m) * 255)));
	else if (60 <= h && h < 120)
		return (rgb_to_int(round((x + m) * 255),
				round((c + m) * 255), round((0 + m) * 255)));
	else if (120 <= h && h < 180)
		return (rgb_to_int(round((0 + m) * 255),
				round((c + m) * 255), round((x + m) * 255)));
	else if (180 <= h && h < 240)
		return (rgb_to_int(round((0 + m) * 255),
				round((x + m) * 255), round((c + m) * 255)));
	else if (240 <= h && h < 300)
		return (rgb_to_int(round((x + m) * 255),
				round((0 + m) * 255), round((c + m) * 255)));
	else
		return (rgb_to_int(round((c + m) * 255),
				round((0 + m) * 255), round((x + m) * 255)));
}

unsigned int	calculate_color(int it, int max_it, t_vars vars)
{
	if (it >= max_it)
		return (0x00000000);
	else
		return (hsv_to_rgb_int(/*277*/((double)it / (double)max_it) * 120.0 * (double)vars.color, (double)it / (double)max_it, 0.8/*(double)it/(double)max_it)*/));
}
