/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 16:47:29 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/27 18:13:11 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	append(char *dst, const char *src, size_t size, size_t dest_size)
{
	size_t	i;

	i = 0;
	while (i < size - dest_size - 1 && src[i] != '\0')
	{
		dst[dest_size + i] = src[i];
		i++;
	}
	dst[dest_size + i] = '\0';
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	dest_size = 0;
	src_size = 0;
	i = 0;
	if (dstsize != 0)
	{
		while (dst[i++] != '\0' && i <= dstsize)
			dest_size++;
	}
	i = 0;
	while (src[i++] != '\0')
		src_size++;
	if ((dst != NULL && src != NULL) && dstsize != 0 && dest_size < dstsize)
		append(dst, src, dstsize, dest_size);
	if (dest_size > dstsize)
		dest_size = dstsize;
	return (dest_size + src_size);
}

// int main()
// {
// 	char *dest;

// 	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
// 		return (0);
// 	memset(dest, 0, 15);
// 	memset(dest, 'r', 6);
// 	printf("%zu\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
// }
