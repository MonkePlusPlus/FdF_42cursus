# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 16:56:21 by ptheo             #+#    #+#              #
#    Updated: 2024/07/26 17:07:05 by ptheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/

# FILE
FILE     = main.c
FILE	+= figure.c
FILE	+= pixel.c
FILE	+= keytouch.c
FILE	+= background.c
FILE	+= render.c
FILE	+= rotation.c
FILE	+= list.c
FILE	+= parsing.c
FILE	+= func_split.c
FILE	+= text.c
FILE	+= color.c
# END FILE

SRC_FILE = $(addprefix $(SRC), $(FILE))

OBJ      := $(SRC_FILE:.c=.o)
INCLUDES := ./includes/

PATH_LIBFT := ./libft/
PATH_MLX   := ./mlx_linux/

LIBFT = $(PATH_LIBFT)libft.a

CC        := cc
FLAGS 	  := -Wall -Werror -Wextra -g3
MLX_FLAGS := -L$(PATH_LIBFT) -lft -Lmlx_linux -lmlx -lXext -lX11 -lm -lz

RM   := rm -rf
NAME := fdf
MAKE := make

#.c.o : 
#	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME) $(PATH_LIBFT) $(PATH_MLX)

$(NAME) : $(OBJ) mlx $(LIBFT)
		@echo "compilation of fdf file :"
		$(CC) $(FLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME) -I$(INCLUDES)

$(LIBFT) : 
	@echo "compilate libft :"
	@$(MAKE) -C $(PATH_LIBFT) all

mlx :
	@echo "compilate mlx :"
	@$(MAKE) -C $(PATH_MLX)

clean :
	@echo "clean libft :"
	@$(MAKE) -C $(PATH_LIBFT) clean
	@echo "clean mlx :"
	@$(MAKE) -C $(PATH_MLX) clean
	$(RM) $(OBJ)

fclean :
	@echo "fclean libft : "
	@$(MAKE) -C $(PATH_LIBFT) fclean
	@echo "clean mlx :"
	@$(MAKE) -C $(PATH_MLX) clean
	$(RM) $(NAME) $(OBJ)

re : fclean all

.PHONY: all clean fclean re
