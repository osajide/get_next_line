/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osajide <osajide@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:10:53 by osajide           #+#    #+#             */
/*   Updated: 2022/11/22 11:14:29 by osajide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

int		ft_strlen(char *str);
void	ft_bzero(char *str, int size);
void	*ft_calloc(int count, int size);
int		ft_strchr(char *buffer, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_reader(int fd, char *buffer);
char	*give_line(char *buffer);
char	*give_rest(char *buffer);
char	*get_next_line(int fd);
#endif
