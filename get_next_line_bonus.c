/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:09:28 by osajide           #+#    #+#             */
/*   Updated: 2022/11/22 14:50:25 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_reader(int fd, char *buffer)
{
	int		readline;
	char	*s;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	s = malloc(BUFFER_SIZE + 1);
	if (!s)
		return (NULL);
	readline = 1;
	while (readline > 0 && !ft_strchr(buffer, '\n'))
	{
		readline = read(fd, s, BUFFER_SIZE);
		if (readline == -1)
		{
			free(s);
			free(buffer);
			return (NULL);
		}
		s[readline] = '\0';
		buffer = ft_strjoin(buffer, s);
	}
	free(s);
	return (buffer);
}

char	*give_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(i + 2);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*give_rest(char *buffer)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (0);
	}
	rest = malloc(ft_strlen(buffer) - i);
	i++;
	j = 0;
	while (buffer[i])
	{
		rest[j] = buffer[i];
		i++;
		j++;
	}
	rest[j] = '\0';
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_reader(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = give_line(buffer[fd]);
	buffer[fd] = give_rest(buffer[fd]);
	return (line);
}
