/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 18:26:53 by tzeck             #+#    #+#             */
/*   Updated: 2021/07/21 18:34:31 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		b;
	char	*ptr;

	i = 0;
	b = -1;
	ptr = (char *)s;
	while (s[i])
	{
		if (s[i] == c)
			b = i;
		i++;
	}
	if (b != -1)
		return (&ptr[b]);
	else if (c == '\0')
		return (&ptr[i]);
	else
		return (NULL);
}
