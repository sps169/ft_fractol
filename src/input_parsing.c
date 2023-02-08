/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:10:40 by sperez-s          #+#    #+#             */
/*   Updated: 2023/02/08 14:18:25 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	wrong_input_free_exit(char trimmed, char *string) {
	if (!ft_isdigit(trimmed))
	{
		printf("Wrong input\n");
		free(string);
		exit(EXIT_FAILURE);
	}
}

static void	wrong_input_exit(char trimmed) {
	if (!ft_isdigit(trimmed))
	{
		printf("Wrong input\n");
		exit(EXIT_FAILURE);
	}
}

static double	ft_atod (char *s)
{
	char	*trimmed;
	size_t	i;
	size_t	j;
	double	result;
	double	neg;

	if (s && ft_strlen(s) > 0 && ft_strlen(s) <= 15)
	{
		trimmed = ft_strtrim(s, " ");
		i = 0;
		result = 0.0;
		neg = 1.0;
		if (trimmed[i] == '-')
		{
			neg = -1.0;
			i++;
		}
		while (i < ft_strlen(trimmed) && trimmed[i] != '.')
		{
			wrong_input_free_exit(trimmed[i], trimmed);
			result = result * 10.0 + trimmed[i] - '0';
			i++;
		}
		i++;
		j = 1;
		while (i < ft_strlen(trimmed))
		{
			wrong_input_free_exit(trimmed[i], trimmed);
			result += (trimmed[i] - '0') / pow(10.0, (double)j);
			i++;
			j++;
		}
		free(trimmed);
		return (neg * result);
	}
	else
		wrong_input_exit('f');
		return (0.0);
}

int	parse_args(t_vars *vars, int argc, char *argv[])
{
	vars->c.r = 0.0;
	vars->c.i = 0.0;
	if (argc == 2 && argv[1][0] == MANDELBROT)
	{
		initial_position(MANDELBROT, vars);
		return (1);
	}
	else if (argc == 2 && argv[1][0] == EXTRA)
	{
		initial_position(EXTRA, vars);
		return (1);
	}
	else if (argc == 4 && argv[1][0] == JULIA)
	{
		vars->c.r = ft_atod(argv[2]);
		vars->c.i = ft_atod(argv[3]);
		initial_position(JULIA, vars);
		return (1);
	}
	else
		return (0);
}

