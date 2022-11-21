/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:04:39 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/27 18:12:36 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned long	counter;
	const char		*psource;
	char			*pdestiny;

	psource = (const char *) src;
	pdestiny = (char *) dst;
	counter = 0;
	if (pdestiny > psource && (dst != NULL || src != NULL))
	{
		counter = len;
		while (counter != 0)
		{
			pdestiny[counter - 1] = psource[counter - 1];
			counter--;
		}
	}
	else
	{
		while (counter < len && (dst != NULL || src != NULL))
		{
			pdestiny[counter] = psource[counter];
			counter++;
		}
	}
	return (dst);
}
