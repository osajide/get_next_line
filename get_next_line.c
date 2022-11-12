/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:20:11 by osajide           #+#    #+#             */
/*   Updated: 2022/11/12 15:58:36 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"
#include<stdio.h>

char	*just_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (0);
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
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*just_remainer(char *buffer)
{
	// if (!buffer)
	// 	return (0);
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	buff = malloc(ft_strlen(buffer) - i + 1);
	i++;
	while (buffer[i])
	{
		buff[j]= buffer[i];
		j++;
		i++;
	}
	buff[j] = '\0';
	free(buffer);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*s;
	int			readline;

	// if (!buffer)
	// 	buffer = calloc(1, 1);
	if (fd < 0 || fd == 2 || fd == 1 || BUFFER_SIZE <= 0)
		return (NULL);
	// if (!buffer)
	// 	buffer = calloc(1, 1);

	s = malloc(BUFFER_SIZE + 1);
	readline = 1;
	while(readline > 0/* && !ft_strchr(s, '\n')*/)
	{
		readline = read(fd, s, BUFFER_SIZE);
		//printf("read: %d\n", readline);
		//printf("string readed: %s\n", s);
		if (readline < 0)
		{
			free(s);
			free(buffer);
			return (NULL);
		}
		// if (readline <= BUFFER_SIZE)
		// {
		s[readline] = '\0';
		//printf("string s: %s\n", s);
		buffer = ft_strjoin(buffer, s);
		//printf("Joined buffer: %s\n", buffer);
		if (ft_strchr(buffer, '\n'))
			break;
		//ft_bzero(s, ft_strlen(s));
		//printf("s after bzero: %s\n", s);
		//}
		// if (readline < BUFFER_SIZE)
		// 	break;
	}
	free(s);
	//printf("BUFFER Before getting the line: %s\n", buffer);
	// if (buffer == NULL)
	// 	return (NULL);
	//printf("s before getting the line: %s\n", s);
	line = just_line(buffer);
	//printf("-----------------------------LINE: %s\n", line);
	//printf("BUFFER after getting the line: %s\n", buffer);
	//printf("s sh7al baqa fih: %s\n", s);
	buffer = just_remainer(buffer);
	//printf("New Buffer: %s\n", buffer);
	return (line);
}

// int main()
// {	
// 	int fd = open("text.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));

// 	// printf("%s\n",just_line(test));
// 	// test = fremainer(test);
// 	// //printf("%s\n",test);
// 	// printf("%s\n",just_line(test));
// 	// test = fremainer(test);
// 	// printf("%s\n",test);
// 	// printf("%s\n",just_line(test));
// 	// test = fremainer(test);
// 	// printf("%s\n",test);
// 	// printf("%s\n",just_line(test));
	
// 	return (0);
// }
