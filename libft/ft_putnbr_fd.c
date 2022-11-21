/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-s <sperez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:36:46 by sperez-s          #+#    #+#             */
/*   Updated: 2021/11/23 20:41:45 by sperez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		aux;
	int		no_sign;

	if (n == -2147483648)
	{
		ft_putnbr_fd(-2, fd);
		ft_putnbr_fd(147483648, fd);
	}
	else
	{
		if (n < 0)
		{
			no_sign = n * -1;
			ft_putchar_fd('-', fd);
		}
		else
			no_sign = n;
		aux = no_sign % 10;
		if (no_sign >= 10)
			ft_putnbr_fd(no_sign / 10, fd);
		ft_putchar_fd(aux + '0', fd);
	}
}
