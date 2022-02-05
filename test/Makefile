# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/05 18:41:31 by coder             #+#    #+#              #
#    Updated: 2022/02/05 18:45:12 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# UPDATE THE FOLLOWING PATHS FOR THE TEST WORK WITH YOUR SO_LONG GAME:
# **************************************************************************** #
# so_long source path - where is the makefile that compiles so_long
SO_LONG_PATH =		../
SO_LONG =			so_long

# **************************************************************************** #

# test sources paths
TEST_FILE =			test.sh

all:	m

m:		sl cat

sl:
		@cd $(SO_LONG_PATH) && $(MAKE)

# test invalid input arguments
tinput: 
		./input_test.sh

cat:
	@echo "\n"
	@echo "\033[1;33m             /\\_______/\\"
	@echo "            /           \\"
	@echo "           /   \033[1;36m<0   0>   \033[1;33m\\"
	@echo "          (    \033[1;37m=  \033[1;35mY  \033[1;37m=    \033[1;33m)"
	@echo "           \             /"
	@echo "           /    ~~~~~    \\"
	@echo "          /               \    (\\"
	@echo "         /        0        \    \\\\"
	@echo "        /  |      0      |  \    ))"
	@echo "       /   |   |  0  |   |   \  //"
	@echo "      /    |   |     |   |    \(("
	@echo "     (     |   |     |   |     )"
	@echo "      \\    |   |     |   |    /"
	@echo "       \\   |   |     |   |   /"
	@echo "        \\_(_;_;_)___(_;_;_)_/"
	@echo ""
	@echo "         by Sheela G. Khusal\n"
	@echo ""

clean:
		@cd $(SO_LONG_PATH) && $(MAKE) $@

fclean:		clean
		@cd $(SO_LONG_PATH) && $(MAKE) $@

re:			fclean all

.PHONY: all clean fclean re