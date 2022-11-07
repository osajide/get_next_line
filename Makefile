# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osajide <osajide@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 12:32:29 by osajide           #+#    #+#              #
#    Updated: 2022/11/07 12:32:41 by osajide          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Werror -Wextra -Wall
NAME = get_next_line.a
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
AR = ar -rcs
RM = rm -rf

%.o : %.c
	cc $(CFLAGS) -c $<

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $^

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all%
