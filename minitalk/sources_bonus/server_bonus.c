/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:20:27 by tisantos          #+#    #+#             */
/*   Updated: 2022/04/30 02:42:18 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	print_message_norminette(char *binary, int *binary_table)
{
	int	converted;
	int	i;

	converted = 0;
	i = 0;
	while (i < 8)
	{
		if (binary[i] == '1')
			converted += binary_table[i];
		i++;
	}
	return (converted);
}

int	print_message(char *binary)
{
	static int	binary_table[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	static char	*message = {0};
	int			converted;
	char		*temp;

	converted = print_message_norminette(binary, binary_table);
	if (converted == 0)
	{
		write(1, message, ft_strlen(message));
		write(1, "\n", 1);
		free(message);
		message = NULL;
		return (1);
	}
	if (message == NULL)
		message = ft_strdup_char((char)converted);
	else
	{
		temp = ft_strjoin_char(message, (char)converted);
		free(message);
		message = temp;
	}
	return (0);
}

void	handle_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	static char	binary[8] = {0};
	static int	bits = 0;

	(void)ucontext;
	if (sig == SIGUSR1)
		binary[bits] = '0';
	if (sig == SIGUSR2)
		binary[bits] = '1';
	bits++;
	if (bits >= 8)
	{
		binary[8] = '\0';
		bits = 0;
		if (print_message(binary) == 1)
		{
			if (kill(info->si_pid, SIGUSR2) == -1)
				ft_perror("No signal was sent!\n", 1);
			return ;
		}
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ft_perror("No signal was sent!\n", 1);
}

void	handling_signals(void)
{
	struct sigaction	sa_sigusr;

	sa_sigusr.sa_sigaction = &handle_sigusr;
	if (sigemptyset(&sa_sigusr.sa_mask) == -1)
		ft_perror("Couldn't empty signal set!", 1);
	sa_sigusr.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_sigusr, NULL) == -1)
		ft_perror("Couldn't register signal handler!", 1);
	if (sigaction(SIGUSR2, &sa_sigusr, NULL) == -1)
		ft_perror("Couldn't register signal handler!", 1);
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
