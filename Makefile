# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/04 21:14:15 by coder             #+#    #+#              #
#    Updated: 2022/02/17 22:08:33 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =					so_long
BONUS =					so_long_bonus

# **************************************************************************** #
# MY LIBRARIES - libft.a and libftprintf.a
PRINTF_PATH =	./my_libs/ft_printf/
LIBFT_PATH =	./my_libs/libft/

PRINTF =		$(PRINTF_PATH)libftprintf.a
LIBFT =			$(LIBFT_PATH)libft.a
LIBFT_HEADER =	$(LIBFT_PATH)src/libft.h
# **************************************************************************** #

# INPUTS

SRC_PATH =			./src
OBJ_PATH =			./obj
SRC_BONUS_PATH =	./bonus
OBJ_BONUS_PATH =	./obj/bonus

SRC_FILES =			1_so_long.c 2_map.c 3_check_map.c 4_game.c \
						5_render_map.c 6_render_collectibles.c \
						7_render_player.c 8_hooks.c 9_move.c 9_move_utils.c\
						so_long_utils_1.c so_long_utils_2.c \
						clean.c clean_utils.c

SRC =				$(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ =				$(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

SRC_BONUS_FILES =	1_so_long.c 2_map.c 3_check_map.c 4_game_bonus.c \
						4_load_sprites_bonus.c \
						5_render_map_bonus.c 6_render_collectibles.c \
						7_render_player_bonus.c 8_hooks_bonus.c \
						9_move_bonus.c 9_move_utils_bonus.c\
						10_set_enemies_bonus.c 11_render_enemies_bonus.c \
						so_long_utils_1_bonus.c so_long_utils_2_bonus.c \
						clean.c clean_utils_bonus.c

SRC_BONUS =			$(addprefix $(SRC_BONUS_PATH)/, $(SRC_BONUS_FILES))
OBJ_BONUS =			$(SRC_BONUS:$(SRC_BONUS_PATH)/%.c=$(OBJ_BONUS_PATH)/%.o)

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

bonus:	$(BONUS)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_PATH)/%.o:	$(SRC_BONUS_PATH)/%.c
	@mkdir -p $(OBJ_BONUS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(LIBFT) $(PRINTF) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) $(PRINTF) $(LIBFT) -o $@

$(BONUS):	$(LIBFT) $(PRINTF) $(OBJ_BONUS)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLXFLAGS) $(PRINTF) $(LIBFT) -o $@

$(LIBFT):
	@cd $(LIBFT_PATH) && $(MAKE)

$(PRINTF):
	@cd $(PRINTF_PATH) && $(MAKE)

clean:
		@$(RM_DIR) $(OBJ_PATH)

fclean:		clean
		@$(RM) $(NAME)
		@$(RM) $(BONUS)

re:			fclean all

reb:		fclean bonus

reall:		fcleanlib re

cleanlib:	
	@cd $(PRINTF_PATH) && $(MAKE) clean
	@cd $(LIBFT_PATH) && $(MAKE) clean

fcleanlib:
	@cd $(PRINTF_PATH) && $(MAKE) fclean
	@cd $(LIBFT_PATH) && $(MAKE) fclean

.PHONY: all clean fclean re
