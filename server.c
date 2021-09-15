/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:26:57 by tzeck             #+#    #+#             */
/*   Updated: 2021/09/15 20:18:32 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

// void	handle_sigtstp(int sig)
// {
// 	printf("stop not allowed\n");
// }

// void	handle_sigcont(int sig)
// {
// 	fflush(stdout);
// 	printf("server pid: 666\n");
// }

void	handle_sigusr(int sig)
{
	if (sig == SIGUSR1)
		printf("%s\n", "1");
	else
		printf("%s\n", "2");
}

int	main(void)
{
#pragma region kill
	// struct sigaction sa;
	// sa.sa_handler = &handle_sigcont;
	// sigaction(SIGCONT, &sa, NULL);

	// signal(SIGTSTP, &handle_sigtstp);

	// printf("server pid: %d\n", getpid()); // print out pid for client
	// while (1)
	// {
	// 	printf("text from loop\n");
	// 	usleep(1000000);
	// }
#pragma endregion
	struct sigaction sa;

	sa.__sigaction_u.__sa_handler = &handle_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("server pid: %d\n", getpid()); // print out pid for client
	while(1) // to get multible calls without stopping
		pause(); //waits until a signal arrives
	return (1);
}
