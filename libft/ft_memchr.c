/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 19:11:55 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/27 18:11:57 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*string;
	long			stored_pos;
	unsigned long	i;

	string = (char *) s;
	stored_pos = -1;
	i = 0;
	while (i < n && stored_pos == -1)
	{
		if (string[i] == (char) c)
			stored_pos = i;
		i++;
	}
	if (stored_pos == -1)
	{
		return (NULL);
	}
	else
		return (&string[stored_pos]);
}
