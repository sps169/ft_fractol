/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:37:05 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/27 15:06:16 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != 0 || s2[i] != 0))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			if (((unsigned char)s1[i] - (unsigned char)s2[i]) > 0)
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (0);
}
// int main()
// {
// 	printf("%d\n", ft_strncmp("test", "", 4));
// 	printf("%d\n", strncmp("test", "", 4));
// }
