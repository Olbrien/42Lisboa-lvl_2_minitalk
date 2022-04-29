/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:20:47 by tisantos          #+#    #+#             */
/*   Updated: 2022/04/29 04:49:05 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# define __USE_POSIX 1
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>

/***********/
/*  Data   */
/***********/
typedef struct s_data
{
	pid_t	target_pid;
	char	*string_to_send;
} t_data;


/***********/
/*  Utils  */
/***********/
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_isstringdigit(char *string);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

# include <stdio.h>

#endif
