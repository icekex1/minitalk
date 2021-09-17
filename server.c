/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:26:57 by tzeck             #+#    #+#             */
/*   Updated: 2021/09/17 12:14:43 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include "minitalk.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	src_len;
	unsigned int	dst_len;
	unsigned int	i;

	src_len = strlen(src);
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

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			write(fd, &s[i], sizeof(char));
			i++;
		}
	}
}

char	*print_string(char *string)
{
	ft_putstr_fd(string, 1);
	free(string);
	return (NULL);
}

void	handle_sigusr(int sig)
{
	static char c;
	static int bits;
	static char *string;
	
	bits = 0;
	c = 0xFF;
	if (sig == SIGUSR1)
		c ^= 0x80 >> bits;
	else if (sig == SIGUSR2)
		c |= 0x80 >> bits;
	if (++bits == 8)
	{
		if (c)
			ft_strlcat(string, &c, 1);
		else
		{
			string = print_string(string);
			bits = 0;
			c = 0xFF;
		}
	}

	// if (sig == SIGUSR1)
	// 	write(1, "0", 1);
	// else if (sig == SIGUSR2)
	// 	write(1, "1", 1);
}

int	main(void)
{
	struct sigaction sa;
	pid_t pid;
	static char *s;
	
	pid = getpid();
	sa.__sigaction_u.__sa_handler = &handle_sigusr;
	printf("server pid: %d\n", pid); // print out pid for client
	while (1) // to get multible calls without stopping	
	{
		sigaction(SIGUSR2, &sa, NULL);
		sigaction(SIGUSR1, &sa, NULL);
		pause(); //waits until a signal arrives
	}
	return (1);
}
