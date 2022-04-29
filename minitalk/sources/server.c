/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:20:27 by tisantos          #+#    #+#             */
/*   Updated: 2022/04/29 04:52:43 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr2(int sig)
{
	(void)sig;
	printf("SIGUSR 2, SERVER!!\n");
}

void	handle_sigusr1(int sig)
{
	(void)sig;
	printf("SIGUSR 1, SERVER!!\n");
}

void	handling_signals()
{
	struct sigaction sa_sigusr1;
	sa_sigusr1.sa_handler = &handle_sigusr1;
	sigemptyset(&sa_sigusr1.sa_mask);
	sa_sigusr1.sa_flags = 0;

	struct sigaction sa_sigusr2;
	sa_sigusr2.sa_handler = &handle_sigusr2;
	sigemptyset(&sa_sigusr2.sa_mask);
	sa_sigusr2.sa_flags = 0;

	sigaction(SIGUSR1, &sa_sigusr1, NULL);
	sigaction(SIGUSR2, &sa_sigusr2, NULL);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "\nServer PID is: ", 16);
	ft_putnbr_fd(pid, 1);
	write(1, "\n\n", 2);

	handling_signals();

	while (1)
	{
		pause();
	}
	return (0);
}
