/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:12:29 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/27 18:13:38 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	stored_pos;

	i = 0;
	stored_pos = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			stored_pos = i;
		i++;
	}
	if (stored_pos != -1)
		return ((char *) &s[stored_pos]);
	else if ((char) c == '\0')
		return ((char *) &s[i]);
	else
		return (NULL);
}
