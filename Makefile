# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/20 17:41:00 by asarandi          #+#    #+#              #
#    Updated: 2017/09/24 19:44:11 by asarandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CFLAGS		= -Wall -Werror -Wextra -I. -c
FILES		= $(wildcard ft_*.c)
OBJ			= $(FILES:%.c=%.o)
DEPS		= libft.h
SONAME		= libft.so
JUNK		= libft.h.gch

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

norm:
	norminette -R CheckForbiddenSourceHeader $(FILES) $(DEPS)
so:
	gcc -c -fPIC $(FILES) $(DEPS)
	gcc -shared -fPIC -o $(SONAME) $(OBJ)

$(OBJ): $(FILES)
	gcc $(CFLAGS) $(FILES) $(DEPS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(SONAME) $(JUNK)

re: fclean all
