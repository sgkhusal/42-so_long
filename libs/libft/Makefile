# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 02:08:39 by sguilher          #+#    #+#              #
#    Updated: 2022/02/17 17:48:17 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Libft Makefile

# Variables

NAME =			libft.a

HEADER =		./src/libft.h
GNL_HEADER =	../gnl/get_next_line.h

SRC_PATH =	./src
GNL_PATH =	../gnl
OBJ_PATH =	./obj

SRC_FILES	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
				ft_memmove.c ft_memchr.c ft_memcmp.c \
				ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
				ft_strrchr.c ft_strnstr.c ft_strncmp.c \
				ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
				ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
				ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c
GNL_FILES =		get_next_line.c get_next_line_utils.c

#SRC_FILES =				$(SO_LONG_FILES) $(LIBFT_FILES) $(GNL_FILES)
SRCS =		$(addprefix $(SRC_PATH)/, $(SRC_FILES))
SRCS_GNL =	$(addprefix $(GNL_PATH)/, $(GNL_FILES))
OBJS =		$(SRCS:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
OBJS_GNL =	$(SRCS_GNL:$(GNL_PATH)/%.c=$(OBJ_PATH)/%.o)

# compilation
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
GNLFLAGS =	-D BUFFER_SIZE=10

# clean
RM =		rm -f
RM_DIR =	rm -rf

# Rules

all:	$(NAME)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/%.o:	$(GNL_PATH)/%.c
	@$(CC) $(CFLAGS) $(GNLFLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(OBJS_GNL) #$(HEADER) $(GNL_HEADER)
	@ar rc $@ $(OBJS) $(OBJS_GNL)
	@ranlib $@

clean:
	@$(RM_DIR) $(OBJ_PATH)

fclean:		clean
	@$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
