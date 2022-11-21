/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:05:31 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/27 18:13:02 by sperez-s         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*result;
	size_t			s1_size;
	size_t			s2_size;
	unsigned int	i;

	s1_size = get_str_len(s1);
	s2_size = get_str_len(s2);
	result = malloc((s1_size + s2_size + 1) * sizeof(char));
	if (result != NULL)
	{
		i = 0;
		while (i < s1_size)
		{
			result[i] = s1[i];
			i++;
		}
		while (i < s1_size + s2_size)
		{
			result[i] = s2[i - s1_size];
			i++;
		}
		result[i] = 0;
	}
	return (result);
}
