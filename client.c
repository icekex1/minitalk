/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:27:01 by tzeck             #+#    #+#             */
/*   Updated: 2021/09/18 12:48:31 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>
#include <string.h>
#include <signal.h>

int	send_bit(int n, int pid)
{
	usleep(10000);
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

	n = c;
	i = 0;
	while (i < 8)
	{
		n = (char)((c << i) & 0x80);
		if (n == -128)
			n = 1;
    	send_bit(n, pid);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int i;
	char *s;

	pid = atoi(argv[1]);
	s = strdup(argv[2]);
	while (s[i] != '\0')
		base_two(s[i++], pid);
	return (1);
}
