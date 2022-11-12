/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 15:36:05 by osajide           #+#    #+#             */
/*   Updated: 2022/11/12 14:32:50 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int		i;
	char	*p;

	i = 0;
	while ((char)str[i] != (char )c && str[i] != '\0')
		i++;
	if ((char)str[i] == (char)c)
	{
		p = (char *)&str[i];
		return (p);
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*str;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	int	*p;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	p = malloc(count * size);
	if (p == 0)
		return (p);
	else
		ft_bzero(p, count * size);
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int			i;
	int			j;
	char		*join;

	if (!s1)
		s1 = ft_calloc(1, 1);
	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && ((char *)s1)[i])
	{
		join[i] = ((char *)s1)[i];
		i++;
	}
	while (s2 && ((char *)s2)[j])
	{
		join[i] = ((char *)s2)[j];
		i++;
		j++;
	}
	join[i] = '\0';
	free(s1);
	return (join);
}
