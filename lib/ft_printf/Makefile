# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 11:29:01 by aaleixo-          #+#    #+#              #
#    Updated: 2024/11/11 16:30:47 by aaleixo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O0
SRCS = ft_printf.c ft_putnbr.c ft_ptr.c 
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	make -C ./Libft/
	make bonus -C  ./Libft
	ar rsc $(NAME) $(OBJS)  Libft/*.o

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	make -C ./Libft clean

fclean: clean
	@rm -f $(NAME)
	make -C ./Libft fclean

re: fclean all