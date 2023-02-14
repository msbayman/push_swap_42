# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amsaoub <amsaoub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 12:15:53 by amsaoub           #+#    #+#              #
#    Updated: 2023/01/11 15:23:53 by amsaoub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = parsing.c \
		push_swap_tools.c \
		push_swap.c \
		libf.c \
		operations.c \
		libf2.c \
		libf3.c \
		operations2.c \
		chyata.c \
		chyata2.c \
		push_swap_tools2.c \
		push_swap_tools3.c \
		push_swap_tools4.c

SRCB = parsing.c \
		 push_swap_tools.c \
		 checker.c \
		 libf.c \
		 operations.c \
		 libf2.c \
		 libf3.c \
		 operations2.c \
		 chyata.c \
		 chyata2.c \
		 push_swap_tools2.c \
		 push_swap_tools3.c \
		 push_swap_tools4.c \
		 get_next_line_utils.c \
		 get_next_line.c \


CC = cc 
CFLAGS = -Wall -Werror -Wextra 
FRM = rm -rf

NAME = push_swap
BNS = checker
HEADER = push_swap.h

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(BNS): $(SRCB) $(HEADER)
	$(CC) $(CFLAGS) $(SRCB) -o $(BNS)

bonus: $(BNS) 

clean:
	$(FRM) $(NAME) $(BNS)

fclean: clean

re: fclean all
	
