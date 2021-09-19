/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschleic <rschleic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:18:16 by rschleic          #+#    #+#             */
/*   Updated: 2021/08/17 22:52:00 by rschleic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_x_convert(unsigned long x)
{
	if (x < 10)
		ft_putnbr_fd(x, 1);
	else if (x == 10)
		ft_putchar_fd('a', 1);
	else if (x == 11)
		ft_putchar_fd('b', 1);
	else if (x == 12)
		ft_putchar_fd('c', 1);
	else if (x == 13)
		ft_putchar_fd('d', 1);
	else if (x == 14)
		ft_putchar_fd('e', 1);
	else if (x == 15)
		ft_putchar_fd('f', 1);
}

void	ft_X_convert(unsigned long x)
{
	if (x < 10)
		ft_putnbr_fd(x, 1);
	else if (x == 10)
		ft_putchar_fd('A', 1);
	else if (x == 11)
		ft_putchar_fd('B', 1);
	else if (x == 12)
		ft_putchar_fd('C', 1);
	else if (x == 13)
		ft_putchar_fd('D', 1);
	else if (x == 14)
		ft_putchar_fd('E', 1);
	else if (x == 15)
		ft_putchar_fd('F', 1);
}

void	ft_puthexa(unsigned long n)
{
	if (n > 0)
	{
		ft_puthexa(n / 16);
		ft_x_convert(n % 16);
	}
}

void	ft_putheXa(unsigned long n)
{
	if (n > 0)
	{
		ft_putheXa(n / 16);
		ft_X_convert(n % 16);
	}
}
