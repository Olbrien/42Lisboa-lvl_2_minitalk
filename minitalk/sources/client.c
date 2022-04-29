/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:20:20 by tisantos          #+#    #+#             */
/*   Updated: 2022/04/29 04:47:21 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr1(int sig)
{
	(void)sig;
	printf("SIGUSR 1, CLIENT!!\n");
}

void	handling_signals()
{
	struct sigaction sa_sigusr1;
	sa_sigusr1.sa_handler = &handle_sigusr1;
	sigemptyset(&sa_sigusr1.sa_mask);
	sa_sigusr1.sa_flags = 0;

	sigaction(SIGUSR1, &sa_sigusr1, NULL);
}

void	parsing(t_data *data, char *target_pid, char *string_to_send)
{
	data->target_pid = ft_atoi(target_pid);
	data->string_to_send = string_to_send;
}

int	main(int argc, char *argv[])
{
	t_data data;

	if (argc < 3)
	{
		write(1, "\nPlease insert the PID and the message!\n\n", 41);
		return (1);
	}
	if (ft_isstringdigit(argv[1]) == 0)
	{
		write(1, "\nPlease insert a valid PID!\n\n", 29);
		return (1);
	}

	parsing(&data, argv[1], argv[2]);
	handling_signals();

	kill(data.target_pid, SIGUSR1);
	kill(data.target_pid, SIGUSR1);
	kill(data.target_pid, SIGUSR2);
	kill(data.target_pid, SIGUSR2);
}
