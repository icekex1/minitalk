/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 14:42:33 by tzeck             #+#    #+#             */
/*   Updated: 2021/07/21 18:34:26 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		c;
	char	*ptr;

	i = 0;
	c = 0;
	ptr = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && len >= ft_strlen(needle))
	{
		j = 0;
		if (haystack[i] == needle[j])
			c = i;
		while (haystack[i + j] == needle[j]
			&& haystack[i + j] != '\0'
			&& needle[j] != '\0')
			j++;
		if (needle[j] == '\0')
			return (&ptr[c]);
		i++;
		len--;
	}
	return (NULL);
}
