# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnolan <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/23 21:24:21 by lnolan            #+#    #+#              #
#    Updated: 2019/01/24 16:24:27 by lnolan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC_D = $(addprefix ./srcs/, $(SRCS))
OBJ_D = objs

GCC = -Wall -Wextra -Werror

SRCS = 	main.c\
		read.c\
		valid.c\
		map.c\
		solve.c\
		print.c\

OBJ = $(addprefix $(OBJ_D)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME):
		make -C ./libft
		gcc $(GCC) -c $(SRC_D) -I ./includes -I ./libft/includes
		mkdir -p $(OBJ_D) && mv $(SRCS:.c=.o) ./$(OBJ_D)/
		gcc $(GCC) -o $(NAME) $(OBJ) -L./libft/ -lft -I ./includes -I ./libft/includes

clean:
		make clean -C ./libft
		rm -f $(OBJ)

fclean: clean
		make fclean -C ./libft
		rm -rf $(NAME)

re:	fclean all
