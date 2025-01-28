# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hajmoham <hajmoham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 15:29:46 by hajmoham          #+#    #+#              #
#    Updated: 2025/01/28 17:07:43 by hajmoham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
BONUS_CLIENT_NAME = client_bonus
SERVER_NAME = server
BONUS_SERVER_NAME = server_bonus

PRINTF = ./Printf/libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = client.c server.c utils.c client_bonus.c server_bonus.c

OBJ = $(SRC:.c=.o)

all: $(CLIENT_NAME) $(SERVER_NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(PRINTF):
	$(MAKE) -C ./Printf

$(CLIENT_NAME): client.o utils.o $(PRINTF)
	$(CC) $(CFLAGS) client.o utils.o $(PRINTF) -o $@
	
$(SERVER_NAME): server.o utils.o $(PRINTF)
	$(CC) $(CFLAGS) server.o utils.o $(PRINTF) -o $@

bonus: $(BONUS_CLIENT_NAME) $(BONUS_SERVER_NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(PRINTF):
	$(MAKE) -C ./Printf

$(BONUS_CLIENT_NAME): client_bonus.o utils.o $(PRINTF)
	$(CC) $(CFLAGS) client_bonus.o utils.o $(PRINTF) -o $@
	
$(BONUS_SERVER_NAME): server_bonus.o utils.o $(PRINTF)
	$(CC) $(CFLAGS) server_bonus.o utils.o $(PRINTF) -o $@

clean:
	$(MAKE) clean -C ./Printf
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./Printf
	$(RM) $(CLIENT_NAME) $(SERVER_NAME) $(BONUS_CLIENT_NAME) $(BONUS_SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re