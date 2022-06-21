# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcomlan < gcomlan@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 22:37:51 by gcomlan           #+#    #+#              #
#    Updated: 2022/06/20 22:01:25 by gcomlan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --------------------------------------------------------------------

GCC = gcc -Wall -Wextra -Werror
SERVER_NAME		=	server
CLIENT_NAME		=	client
#Files
SRC		=	server.c client.c minitalk.c
#Obj
SRC_OBJS		=	$(SRC:.c=.o)

# ------------------------------ Colors ------------------------------

BLACK			=	\033[0;30m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
ORANGE			=	\033[0;33m
BLUE			=	\033[0;34m
PURPLE			=	\033[0;35m
CYAN			=	\033[0;36m
LIGHT_GRAY		=	\033[0;37m
DARK_GRAY		=	\033[1;30m
LIGHT_RED		=	\033[1;31m
LIGHT_GREEN		=	\033[1;32m
YELLOW			=	\033[1;33m
LIGHT_BLUE		=	\033[1;34m
LIGHT_PURPLE	=	\033[1;35m
LIGHT_CYAN		=	\033[1;36m
WHITE			=	\033[1;37m
NO_COLOR		=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(PURPLE)Make: $(NO_COLOR)Starting the compilation...\n"

SERV_READY	=	echo "\n📥 Server ready!\n"

CLI_READY	=	echo "\n📟 Client ready!\n"

CLEANED		=	echo "\n💧 $(GREEN)Clean: $(NO_COLOR)Removed all the \".o\" files 🗑\\n"

FCLEANED	=	echo "\n🧼 $(GREEN)Fclean: $(NO_COLOR)Removed the executables 🗑\\n"

NEW_LINE	=	echo "\n"

# ------------------------------ Rules ---------------------------------

all : $(NAME_SERVER) $(NAME_CLIENT)
	make -C ./lib/
	cp ./lib/libminitalk.a .
	@$(NEW_LINE)
	gcc server.c display.c -L. libminitalk.a -o server
	@$(SERV_READY)
	gcc client.c display.c -L. libminitalk.a -o client
	@$(CLI_READY)

clean :
	rm -f *.o
	make -C ./lib/ clean
	@$(CLEANED)

fclean : clean
	rm -f server client
	make -C ./lib/ fclean
	rm -f libminitalk.a
	@$(FCLEANED)

re : fclean all

.PHONY : all clean fclean re
