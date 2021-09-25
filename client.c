/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzeck <tzeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:27:01 by tzeck             #+#    #+#             */
/*   Updated: 2021/09/25 10:52:51 by tzeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	send_bit(int n, int pid)
{
	usleep(80);
	if (n == 0)
		kill(pid, SIGUSR1);
	else if (n == 1)
		kill(pid, SIGUSR2);
	return (1);
}

int	base_two(char c, int pid)
{
	int	n;
	int	i;

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
	int		pid;
	int		i;
	char	*s;

	i = 0;
	if (argc != 3)
		ft_putstr_fd("Wrong number of arguments!", 1);
	else
	{
		pid = ft_atoi(argv[1]);
		s = ft_strdup(argv[2]);
		while (s[i] != '\0')
			base_two(s[i++], pid);
		free(s);
	}
	system("leaks client");
	return (1);
}
