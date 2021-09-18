/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:26:57 by tzeck             #+#    #+#             */
/*   Updated: 2021/09/18 21:14:11 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

int	convert(int n)
{
	int	base;
	int	rem;
	int	dec;

	base = 1;
	while (n > 0)
	{
		rem = n % 10;
		dec = dec + rem * base;
		n = n / 10;
		base = base * 2;
	}
	return (dec - 1);
}

void	bin_to_char(char *s)
{
	int		n;

	n = ft_atoi(s); //problem is here :)
	ft_putnbr_fd(n, 1);
	n = convert(n);
	// ft_putstr_fd("test2: ", 1);
	// ft_putnbr_fd(n, 1);
	char c = n;
	write(1, &c, 1);
	// ft_putchar_fd('\n', 1);
	// ft_putchar_fd(n, 1);
}

void	handle_sigusr(int sig)
{
	static int	i;
	static char	*string;

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
		bin_to_char(string);
		free(string);
		string = NULL;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;
	static char			*s;

	pid = getpid();
	sa.__sigaction_u.__sa_handler = &handle_sigusr;
	ft_putstr_fd("server pid: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (1);
}
