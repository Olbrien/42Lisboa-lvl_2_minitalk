/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:20:20 by tisantos          #+#    #+#             */
/*   Updated: 2022/04/30 02:37:53 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message_norminette(char *message, int count, int bits,
								int target_pid)
{
	usleep(10);
	if ((message[count] >> bits & 1) == 0)
	{
		if (kill(target_pid, SIGUSR1) == -1)
			ft_perror("No signal was sent!\n", 1);
	}
	else if ((message[count] >> bits & 1) == 1)
	{
		if (kill(target_pid, SIGUSR2) == -1)
			ft_perror("No signal was sent!\n", 1);
	}
}

void	send_message(int _target_pid, char *_message)
{
	static int	target_pid = 0;
	static char	*message = 0;
	static int	count = 0;
	static int	bits = 7;

	if (_message != 0)
		message = _message;
	if (_target_pid != 0)
		target_pid = _target_pid;
	if (message[count] != '\0')
	{
		send_message_norminette(message, count, bits, target_pid);
		bits--;
	}
	else if (message[count] == '\0')
		if (kill(target_pid, SIGUSR1) == -1)
			ft_perror("No signal was sent!\n", 1);
	if (bits < 0)
	{
		bits = 7;
		count++;
	}
}

void	handle_sigusr(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	if (sig == SIGUSR1)
	{
		send_message(0, 0);
	}
	if (sig == SIGUSR2)
		ft_perror("Message has been received !\n", 0);
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

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (ft_perror("\nPlease insert the PID and the message!\n\n", -1));
	if (ft_isstringdigit(argv[1]) == 0)
		return (ft_perror("\nPlease insert a valid PID!\n\n", -1));
	if (*argv[2] == 0)
		return (ft_perror("\nPlease insert a non empty message!\n\n", -1));
	handling_signals();
	send_message(ft_atoi(argv[1]), argv[2]);
	while (1)
	{
		pause();
	}
}
