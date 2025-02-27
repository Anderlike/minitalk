# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 16:41:24 by aaleixo-          #+#    #+#              #
#    Updated: 2025/02/20 16:41:24 by aaleixo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

C_SOURCES = client.c
S_SOURCES = server.c

C_OBJECTS = $(C_SOURCES:.c=.o)
S_OBJECTS = $(S_SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFTPRINTF = ./lib/ft_printf/libftprintf.a

all: $(SERVER) $(CLIENT)

$(CLIENT): $(C_OBJECTS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) $(C_OBJECTS) -L./lib/ft_printf -lftprintf

$(SERVER): $(S_OBJECTS) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) $(S_OBJECTS) -L./lib/ft_printf -lftprintf

$(LIBFTPRINTF):
	make -C ./lib/ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(C_OBJECTS)
	rm -f $(S_OBJECTS)
	make clean -C ./lib/ft_printf

fclean: clean
	rm -f $(CLIENT)
	rm -f $(SERVER)
	make fclean -C ./lib/ft_printf

re: fclean all

.PHONY: all clean fclean re