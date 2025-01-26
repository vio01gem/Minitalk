# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 15:29:46 by hajmoham          #+#    #+#              #
#    Updated: 2025/01/26 18:07:08 by hajmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server
PRINTF = Printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = client.c server.c utils.c
OBJ = $(SRC:.c=.o)

all: $(CLIENT_NAME) $(SERVER_NAME)

$(PRINTF)
	$(MAKE) -C ./libftprintf

$(CLIENT_NAME): client.o utils.o $(PRINTF)
	$(CC) $(CFLAGS) client.o utils.o $(PRINTF) -o $(CLIENT_NAME)

$(SERVER_NAME): server.o utils.o $(PRINTF)
	$(CC) $(CFLAGS) server.o utils.o $(PRINTF) -o $(SERVER_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(MAKE) clean -C ./Printf
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./Printf
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re
