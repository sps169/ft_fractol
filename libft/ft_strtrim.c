/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 13:01:57 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/27 22:10:16 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_str_len(char const *s)
{
	size_t	len;

	len = 0;
	if (s != NULL)
	{
		while (s[len] != 0)
			len++;
	}
	return (len);
}

static short	is_set_character(char c, const char *set)
{
	int	i;

	if (set != NULL)
	{
		i = 0;
		while (set[i] != 0)
		{
			if (set[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

static char	*create_string(char const *s1, size_t new_str_len, int start)
{
	char			*new_str;
	unsigned int	i;

	new_str = NULL;
	new_str = malloc((new_str_len + 1) * sizeof(char));
	if (new_str != NULL)
	{
		i = 0;
		while (i < new_str_len)
		{
			new_str[i] = s1[i + start];
			i++;
		}
		new_str[i] = 0;
	}
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	new_str_len;
	int		start;
	int		end;

	start = 0;
	end = 0;
	new_str = NULL;
	new_str_len = 0;
	if (get_str_len(s1) > 0)
	{
		end = get_str_len(s1) - 1;
		while (is_set_character(s1[start], set) && s1[start + 1] != 0)
			start++;
		while (is_set_character(s1[end], set) && end != start - 1)
			end--;
		if (!(end - start < 0))
			new_str_len = end - start + 1;
	}
	new_str = create_string(s1, new_str_len, start);
	return (new_str);
}
