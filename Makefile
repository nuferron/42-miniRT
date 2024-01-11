# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 16:44:50 by nuferron          #+#    #+#              #
#    Updated: 2024/01/11 20:48:50 by nuferron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
RESET = \033[0m

SRCS =	main.c check_input.c scene_init.c num_utils.c free_stuff.c
SRCDIR = src/
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
OBJDIR = obj/
NAME = miniRT
CFLAGS = -Wall -Wextra -Werror -O3 #-fsanitize=address
LIB = inc/libft/libft.a
INC = inc/
MLXFLAGS = -Linc/mlx -lmlx -framework OpenGL -framework AppKit
COLUMNS = $(shell tput cols)

all: make_libs ${NAME}

make_libs:
	make -C inc/libft bonus --no-print-directory
	@make -s -C inc/mlx --no-print-directory

${NAME}: ${OBJS}
	cc ${CFLAGS} ${OBJS} ${MLXFLAGS} ${LIB} -o ${NAME}
	echo "${WHITE}${NAME}: ${GREEN}Binary successfully created!${RESET}"

norm:
	make -C inc/libft norm --no-print-directory
	printf "${WHITE}${NAME}${RESET}"
	(norminette ${SRCDIR} && echo " ${GREEN}All good")  | grep -v "OK" \
	| awk '{if($$2 == "Error!") print "\n${RED}"$$1" "$$2; \
	else print "${RESET}"$$0}'

leaks: ${NAME}
	leaks -atExit -- ./${NAME} ${MAP}

${OBJDIR}%.o: ${SRCDIR}%.c ${HEADER}
	@printf "${WHITE}${NAME}: ${CYAN}Compiling files: ${WHITE}$(notdir $<)...${RESET}\r"
	@mkdir -p $(dir $@)
	@cc ${CFLAGS} -I ${INC} -c $< -o $@
	@printf "\r%-${COLUMNS}s\r"

clean:
	if [ -d ${OBJDIR} ] ; then \
		rm -rf ${OBJDIR} ${OBJDIR_BNS} combination; \
		printf "${WHITE}${NAME}: ${RED}Objects have been deleted${RESET}\n"; \
	fi
	make -C inc/libft clean --no-print-directory

fclean: 	clean
	if [ -e ${NAME} ] || [ -e ${LIB} ] ; then \
		rm -f ${NAME} ${LIB} do_bonus ; \
		printf "${WHITE}${NAME}: ${RED}All existing binaries have been deleted${RESET}\n" ; \
	else printf "${WHITE}${NAME}: ${PURPLE}Already cleaned${RESET}\n" ; \
	fi
	make -C inc/libft fclean --no-print-directory
	@make -s -C inc/mlx clean --no-print-directory

re:	fclean all

.SILENT: norm clean fclean leaks make_libs ${NAME}
.PHONY: all clean fclean re leaks norm
