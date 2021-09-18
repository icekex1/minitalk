/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:26:57 by tzeck             #+#    #+#             */
/*   Updated: 2021/09/18 13:37:15 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include "minitalk.h"

// void bin_to_char(char *s)
// {
// 	int	n;
// 	char c;

// 	n = atoi(s);
// 	n += 0b00000000;
// 	c = n;
// 	write(1, &c, 1);
	
// }

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

void	handle_sigusr(int sig)
{
	static int i;
	static char *string;
	
	if (string == NULL)
		string = malloc(9 * sizeof(char));
	if (i < 8)
	{
		if (sig == SIGUSR1)
			string[i] = '0';
		else if (sig == SIGUSR2)
			string[i] = '1';
		i++;
	}
	if (i == 8)
	{
		string[i + 1] = '\0';
		ft_putstr_fd(string, 1);
		free(string);
		string = NULL;
		i = 0;
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
