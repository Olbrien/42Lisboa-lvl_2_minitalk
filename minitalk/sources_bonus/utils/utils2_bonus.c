/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tisantos <tisantos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 03:20:10 by tisantos          #+#    #+#             */
/*   Updated: 2022/04/30 02:25:25 by tisantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strdup_char(char chr)
{
	char	*dest;

	dest = malloc(sizeof(char *) * 2);
	if (dest == NULL)
		return (NULL);
	dest[0] = chr;
	dest[1] = '\0';
	return (dest);
}

char	*ft_strjoin_char(char *s1, char s2)
{
	int		i;
	char	*temp;
	int		len;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	temp = malloc((len + 2) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = s2;
	i++;
	temp[i] = '\0';
	return (temp);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_perror(char *message, int value)
{
	write(2, message, ft_strlen(message));
	if (value == 0)
		exit(EXIT_SUCCESS);
	if (value == 1)
		exit (EXIT_FAILURE);
	return (1);
}
