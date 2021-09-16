/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:27:01 by tzeck             #+#    #+#             */
/*   Updated: 2021/09/16 11:18:38 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <string.h>

int	send_bit(int n, int pid)
{
	usleep(50);
	if (n == 0)
		kill(pid, SIGUSR1); // either call 1 or 2 to let server know if bit is 1 or 0 (what a dumb system to share data wtf)
	else if (n == 1)
		kill(pid, SIGUSR2);
		return (1);
}

int	base_two(char c, int pid) //put stuff liek string and pid in struct
{
	int n;
	int i;
	int j;

	i = 0;
	j = 0;
	// s = calloc(9, 1);
	//make stuff to binary
	while (i < 8)
	{
		n = (char)((c << i) & 0x80);
		if (n == -128)
			n = 1;
    	send_bit(n, pid);
		i++;
		j++;
	}
	// printf("%s", s);
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int i;
	char *s = "a";

	pid = atoi(argv[1]);
	// s = ;//strdup(argv[2]);
	// printf("pid from server: %s\n", argv[1]);
	// printf("pid from client: %d\n", getpid());
	// printf("message from client: %s\n", argv[2]);
	sleep(1);
	kill(pid, SIGUSR1);
	// sleep(1);
	// kill(pid, SIGUSR2);
	while (s[i] != '\0')
	{
		base_two(s[i], pid);
		i++;
	}
	return (1);
}
