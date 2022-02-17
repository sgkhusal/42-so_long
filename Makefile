# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 21:14:15 by coder             #+#    #+#              #
#    Updated: 2022/02/17 17:50:01 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =					so_long

# **************************************************************************** #
# MY LIBRARIES - libft.a and libftprintf.a
PRINTF_PATH =	./my_libraries/ft_printf/
LIBFT_PATH =	./my_libraries/libft/

PRINTF =		$(PRINTF_PATH)libftprintf.a
LIBFT =			$(LIBFT_PATH)libft.a
# **************************************************************************** #

# INPUTS

SRC_PATH =				./src
OBJ_PATH =				./obj

SRC_FILES =			1_so_long.c 2_map.c 3_check_map.c 4_game.c \
						5_render_map.c 6_render_collectibles.c \
						7_render_player.c 8_hooks.c 9_move.c \
						so_long_utils.c clean.c clean_utils.c

SRC =					$(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ =					$(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

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

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(LIBFT) $(PRINTF) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) $(LIBFT) $(PRINTF) -o $@

$(LIBFT):
	@cd $(LIBFT_PATH) && $(MAKE)

$(PRINTF):
	@cd $(PRINTF_PATH) && $(MAKE)

clean:
		@$(RM_DIR) $(OBJ_PATH)

fclean:		clean
		@$(RM) $(NAME)

re:			fclean all

reall:		fcleanlib re

cleanlib:	
	@cd $(PRINTF_PATH) && $(MAKE) clean
	@cd $(LIBFT_PATH) && $(MAKE) clean

fcleanlib:
	@cd $(PRINTF_PATH) && $(MAKE) fclean
	@cd $(LIBFT_PATH) && $(MAKE) fclean

.PHONY: all clean fclean re
