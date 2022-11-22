/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:10:31 by osajide           #+#    #+#             */
/*   Updated: 2022/11/22 11:24:53 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(char *str, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(int count, int size)
{
	void	*p;

	p = malloc(count * size);
	if (p == 0)
		return (p);
	else
		ft_bzero(p, count * size);
	return (p);
}

int	ft_strchr(char *buffer, char c)
{
	int		i;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new_buffer;

	new_buffer = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_buffer)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new_buffer[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new_buffer[i] = s2[j];
		i++;
		j++;
	}
	new_buffer[i] = '\0';
	free(s1);
	return (new_buffer);
}
