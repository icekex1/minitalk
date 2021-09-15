/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:27:01 by tzeck             #+#    #+#             */
/*   Updated: 2021/09/15 20:23:10 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	base_two(char *s, int pid) //put stuff liek string and pid in struct
{
	int n;

	n = 0;
	//make stuff to binary


	// need usleep if data get send to fast so overlapping doesnt happen
	if (n == 0)
		kill(SIGUSR1, pid); // either call 1 or 2 to let server know if bit is 1 or 0 (what a dumb system to share data wtf)
	else if (n == 1)
		kill(SIGUSR2, pid);

	return(1);
}

int	main(int argc, char **argv)
{
	int	pid;
	int i;
	char *s;

	i = 0;
	*s = argv[2];
	pid = atoi(argv[1]);
	// printf("pid from server: %s\n", argv[1]);
	// printf("pid from client: %d\n", getpid());
	// printf("message from client: %s\n", argv[2]);
	sleep(1);
	while (s[i] != NULL)
	{
		base_two(s[i], pid);
		i++;
	}
	return (1);
}
