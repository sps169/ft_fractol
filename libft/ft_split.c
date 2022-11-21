/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 12:08:03 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/27 22:24:50 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_n_splits(char const *s, char delim)
{
	int	n_splits;
	int	i;
	int	word_found;

	n_splits = 0;
	i = 0;
	word_found = 0;
	while (s[i] != 0)
	{
		while (s[i] == delim && s[i] != 0)
			i++;
		while (s[i] != delim && s[i] != 0)
		{
			i++;
			word_found = 1;
		}
		if (word_found)
		{
			n_splits++;
			word_found = 0;
		}
	}
	return (n_splits);
}

static int	save_string(const char *s, char *string, int end, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		string[i] = s[end - len + i];
		i++;
	}
	string[i] = '\0';
	return (0);
}

static int	pre_save_string(const char *s, char **matrix, t_split_args ints)
{
	int	i;

	if (matrix[ints.curr_n] == NULL)
	{
		i = 0;
		while (i < ints.curr_n)
			free(matrix[i++]);
		free(matrix);
		return (-1);
	}
	save_string(s, matrix[ints.curr_n], ints.i, ints.len);
	return (0);
}

static int	run_string(const char *s, char **matrix, char delim, int n_splits)
{
	t_split_args	ints;

	ints.i = 0;
	ints.len = 0;
	ints.curr_n = 0;
	ints.n = n_splits;
	while (ints.curr_n < n_splits)
	{
		if ((s[ints.i] == delim || s[ints.i] == 0) && ints.len != 0)
		{
			matrix[ints.curr_n] = malloc((ints.len + 1) * sizeof(char));
			if (pre_save_string(s, matrix, ints) == -1)
				return (-1);
			ints.curr_n++;
			ints.len = -1;
		}
		else if (s[ints.i] == delim && ints.len == 0)
			ints.len = -1;
		ints.len++;
		ints.i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		n_splits;
	char	**matrix;

	n_splits = 0;
	matrix = NULL;
	if (s == NULL)
		return (NULL);
	n_splits = count_n_splits(s, c);
	matrix = malloc((n_splits + 1) * sizeof(char *));
	if (matrix == NULL)
		return (NULL);
	matrix[n_splits] = NULL;
	if (n_splits == 0)
		return (matrix);
	run_string(s, matrix, c, n_splits);
	return (matrix);
}
