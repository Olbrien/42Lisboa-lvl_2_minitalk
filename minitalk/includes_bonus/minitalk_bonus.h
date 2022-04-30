/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:20:47 by tisantos          #+#    #+#             */
/*   Updated: 2022/04/30 03:07:29 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# define __USE_POSIX 1
# define __USE_POSIX199309 1
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>

/***********/
/*  Utils  */
/***********/
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_isstringdigit(char *string);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

char	*ft_strdup_char(char chr);
char	*ft_strjoin_char(char *s1, char s2);
size_t	ft_strlen(const char *s);
int		ft_perror(char *message, int value);

#endif
