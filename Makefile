# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnicoara <mnicoara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 10:29:59 by mnicoara          #+#    #+#              #
#    Updated: 2018/02/06 14:03:33 by mnicoara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = checking_mat.c \
		valid.c \
		swap.c \
		check.c \
		verify_mat.c \
		copy_mat.c \
		set_mat.c \
		restrain.c \
		solv.c\
		main.c

OBJ = $(SRC:.c=.o)

INCL = -I fillit.h -I libft/libft.h

all: $(NAME)

$(NAME):
		make -C ./libft/
	    gcc -Wall -Werror -Wextra $(INCL) -c $(SRC)
		gcc $(OBJ) -L libft/ -lft -o $(NAME)
clean:
	make clean -C ./libft/
	rm -rf $(OBJ)
fclean: clean
	make fclean -C ./libft/
	rm -rf $(NAME) 
re:	fclean all
