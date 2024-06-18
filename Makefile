# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 16:56:21 by ptheo             #+#    #+#              #
#    Updated: 2024/06/18 18:14:18 by ptheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/
SRC_LIB = ./src_lib/
SRC_FTPRINTF = ./src_ftprintf/
SRC_GNL = ./src_gnl/

SRC_FILE = $(addprefix $(SRC),*.c) $(addprefix $(SRC_LIB),*.c) 
SRC_FILE += $(addprefix $(SRC_FTPRINTF),*.c) $(addprefix $(SRC_GNL),*.c)

OBJ = $(SRC_FILE:.c=.o)

INCLUDES = ./includes/

CC = clang
FLAGS = -Wall -Werror -Wextra

RM = rm -rf
NAME = fdf

.c.o : 
	${CC} ${CFLAGS} -c $< -o $@

all : $(NAME)

$(NAME) : $(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) $(NAME) $(OBJ)

re : fclean all

.PHONY: all clean fclean re