/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 18:02:53 by tzeck             #+#    #+#             */
/*   Updated: 2021/07/21 18:39:56 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	src_len;
	unsigned int	dst_len;
	unsigned int	i;

	src_len = ft_strlen(src);
	dst_len = 0;
	if (dstsize == 0)
		return (src_len);
	while (dst_len < dstsize && dst[dst_len])
		dst_len++;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (dstsize && (--dstsize - dst_len) && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
