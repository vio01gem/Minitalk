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

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = client.c server.c utils.c

OBJ = $(SRC:.c=.o)

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): client.o utils.o
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER_NAME): server.o utils.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all
