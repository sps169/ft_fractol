/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:57:47 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/27 18:12:04 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_total_int_digits(int n)
{
	int	digits;

	digits = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits + 1);
}

static char	*fill_ascii(char *ascii_n, int n, int size)
{
	int	digit;

	ascii_n = malloc((size + 1) * sizeof(char));
	if (ascii_n == NULL)
		return (NULL);
	ascii_n[size] = 0;
	size--;
	if (n < 0)
		ascii_n[0] = '-';
	while (n / 10 != 0)
	{
		digit = (n % 10);
		if (digit < 0)
			digit *= -1;
		ascii_n[size] = digit + '0';
		size--;
		n = n / 10;
	}
	if (n < 0)
		n *= -1;
	ascii_n[size] = (n % 10) + '0';
	return (ascii_n);
}

char	*ft_itoa(int n)
{
	char	*ascii_n;
	int		size;

	ascii_n = NULL;
	size = 0;
	size = get_total_int_digits(n);
	if (n < 0)
		size++;
	ascii_n = fill_ascii(ascii_n, n, size);
	return (ascii_n);
}
