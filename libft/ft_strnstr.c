/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:55:12 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/29 12:26:53 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_needle(char *haystack, char *needle)
{
	int	i;
	int	is_needle;

	i = 0;
	is_needle = 1;
	if (needle != NULL)
	{
		while (needle[i] != '\0')
		{
			if (haystack[i] != needle[i])
				is_needle = 0;
			i++;
		}
	}
	return (is_needle);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*first_occ;
	size_t	i;

	first_occ = NULL;
	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0] && i + ft_strlen(needle) <= len)
		{
			first_occ = (char *)&haystack[i];
			if (is_needle(first_occ, (char *)needle))
				return (first_occ);
			else
				first_occ = NULL;
		}
		i++;
	}
	return (first_occ);
}
