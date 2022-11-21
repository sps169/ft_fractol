/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:54:02 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/27 18:12:21 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	char			*string1;
	char			*string2;

	i = 0;
	string1 = (char *)s1;
	string2 = (char *)s2;
	while (i < n)
	{
		if (string1[i] != string2[i])
		{
			return ((unsigned char) string1[i] - (unsigned char) string2[i]);
		}
		i++;
	}
	return (0);
}
