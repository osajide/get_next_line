/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:20:11 by osajide           #+#    #+#             */
/*   Updated: 2022/11/11 18:58:43 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>

char *just_line(char *buffer)
{
	int i;
	char *line;

	if (!buffer)
		return (0);
	i = 0;
	//printf("BEFORE: %s\n", buffer);
	while (buffer[i] && buffer[i]!= '\n')
		i++;
	line = malloc(i  + 2);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	//printf("AFTER: %s\n", buffer);
	if (buffer[i] == '\n' && buffer[i])
		line[i++] = '\n';
	line[i] = '\0';
	
	// free(buffer);
	return (line);
}

char *fremainer(char *buffer)
{
	if (!buffer)
		return (0);
	char	*buff;
	int	i;
	int j;
	i =0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (0);
	buff = malloc(ft_strlen(buffer) - i + 1);
	i++;
	while (buffer[i])
	{
		buff[j]= buffer[i];
		j++;
		i++;
	}
	buff[j] = '\0';
	return (buff);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;
	char *s;
	int i;
	int readline;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return 0;
	i = 0;
	s = malloc(BUFFER_SIZE + 1);
	readline = 1;
	while(readline > 0 && !ft_strchr(s, '\n'))
	{
		readline = read(fd, s, BUFFER_SIZE);
	//	printf("read: %d\n", readline);
	//	printf("string readed: %s\n", s);
		if (readline < 0)
		{
			free(s);
			return (NULL);
		}
		else if (readline == 0)
			return (NULL);
		s[BUFFER_SIZE] = '\0';
		//printf("string readed: %s\n", s);
		buffer = ft_strjoin(buffer, s);
	//	printf("Joined buffer: %s\n", buffer);
		ft_bzero(s, ft_strlen(s));
	//	printf("s after bzero: %s\n", s);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(s);
	//printf("BUFFER BEFORE: %s\n", buffer);
	// if (buffer == NULL)
	// 	return (NULL);
	line = just_line(buffer);
	//printf("-----------------------------LINE: %s\n", line);
//	printf("BUFFER after getting the line: %s\n", buffer);
	buffer = fremainer(buffer);
//	printf("Buffer remain: %s\n", buffer);
	return (line);
}

int main()
{	
	int fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	// char	*test = "hello\nhh\nxdcd\n";
	// printf("%s\n",just_line(test));
	// test = fremainer(test);
	// //printf("%s\n",test);
	// printf("%s\n",just_line(test));
	// test = fremainer(test);
	// printf("%s\n",test);
	// printf("%s\n",just_line(test));
	// test = fremainer(test);
	// printf("%s\n",test);
	// printf("%s\n",just_line(test));
	
	return (0);
}
