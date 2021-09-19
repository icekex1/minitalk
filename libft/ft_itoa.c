/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:57:19 by tzeck             #+#    #+#             */
/*   Updated: 2021/07/21 18:48:53 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_count(int n)
{
	size_t	l;

	l = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		l++;
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*s;

	num = n;
	len = digit_count(num);
	s = malloc(sizeof(char) * len + 1);
	if (s == NULL)
		return (NULL);
	if (num < 0)
	{
		s[0] = '-';
		num *= (-1);
	}
	if (num == 0)
		s[0] = '0';
	s[len--] = '\0';
	while (num)
	{
		s[len] = num % 10 + '0';
		len--;
		num /= 10;
	}
	return (s);
}
