# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 21:14:15 by coder             #+#    #+#              #
#    Updated: 2022/02/13 00:39:52 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =					so_long

# INPUTS

SRC_PATH =				./src
OBJ_PATH =				./obj
HEADER_PATH = 			./headers

SO_LONG_FILES =			1_so_long.c 2_map.c 3_check_map.c 4_game.c \
						5_images_init.c 6_render_map.c 7_render_collectible.c \
						clean.c so_long_utils.c
LIBFT_FILES =			libft_1.c libft_ft_split.c libft_2.c
GET_NEXT_LINE_FILES =	get_next_line.c get_next_line_utils.c
SRC_FILES =				$(SO_LONG_FILES) $(LIBFT_FILES) $(GET_NEXT_LINE_FILES)
HEADER_FILES =			libft.h get_next_line.h so_long.h

SRC =					$(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ =					$(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
HEADER =				$(addprefix $(HEADER_PATH)/, $(HEADER_FILES))

# **************************************************************************** #

# compilation
CC =		gcc
CFLAGS =	-Wall -Werror -Wextra
GNLFLAGS =	-D BUFFER_SIZE=10
MLXFLAGS =	-lmlx -lXext -lX11

# clean
RM =		-rm -f
RM_DIR =	rm -rf

# **************************************************************************** #
# rules

all:	$(NAME)

#bonus:	$(BONUS)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c $(HEADER)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(GNLFLAGS) -c $< -o $@

$(NAME):	$(OBJ) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -o $@

clean:
		@$(RM_DIR) $(OBJ_PATH)

fclean:		clean
		@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
