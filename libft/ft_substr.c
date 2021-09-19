/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:22:24 by tzeck             #+#    #+#             */
/*   Updated: 2021/07/21 18:37:14 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	z;

	i = 0;
	p = malloc((len + 1) * sizeof(char));
	if (s == NULL || p == NULL)
		return (NULL);
	z = ft_strlen(s);
	if (start >= z)
	{
		p[i] = '\0';
		return (p);
	}
	while (i < len && s[start] != '\0')
	{
		p[i] = s[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
