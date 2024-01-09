# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 16:44:50 by nuferron          #+#    #+#              #
#    Updated: 2024/01/09 16:44:59 by nuferron         ###   ########.fr        #
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

SRCS =	main.c
SRCDIR = src/
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
OBJDIR = obj/
NAME = miniRT
HEADER =
CFLAGS = -Wall -Wextra -Werror -O3 #-fsanitize=address
MLXHEADER = mlx.h
LIB = libftprintf.a
MLXFLAGS = -Linc/minilibx -lmlx -framework OpenGL -framework AppKit
COLUMNS = $(shell tput cols)

all: make_libs ${NAME}

make_libs:
	make -C inc/ft_printf bonus --no-print-directory

${NAME}: ${OBJS}
	cp inc/ft_printf/libftprintf.a .
	cc ${CFLAGS} ${OBJS} ${MLXFLAGS} libftprintf.a -o ${NAME}
	echo "${WHITE}${NAME}: ${GREEN}Binary successfully created!${RESET}"

norm:
	make -C inc/ft_printf norm --no-print-directory
	printf "${WHITE}${NAME}${RESET}\n"
	norminette $(addprefix ${SRCDIR},$(SRCS)) $(addprefix ${SRCDIR_BNS},$(SRCS_BNS)) ${HEADER} | grep -v "OK" \
	| awk '{if($$2 == "Error!") print "${RED}"$$1" "$$2; \
	else print "${RESET}"$$0}'

leaks: ${NAME}
	leaks -atExit -- ./${NAME} ${MAP}

${OBJDIR}%.o: ${SRCDIR}%.c ${HEADER}
	@printf "${WHITE}${NAME}: ${CYAN}Compiling files: ${WHITE}$(notdir $<)...${RESET}\r"
	@mkdir -p $(dir $@)
	@cc ${CFLAGS} -c $< -o $@
	@printf "\r%-${COLUMNS}s\r"

clean:
	if [ -d ${OBJDIR} ] ; then \
		rm -rf ${OBJDIR} ${OBJDIR_BNS} combination; \
		printf "${WHITE}${NAME}: ${RED}Objects have been deleted${RESET}\n"; \
	fi
	make -C inc/ft_printf clean --no-print-directory

fclean: 	clean
	if [ -e ${NAME} ] || [ -e ${LIB} ] ; then \
		rm -f ${NAME} ${LIB} do_bonus ; \
		printf "${WHITE}${NAME}: ${RED}All existing binaries have been deleted${RESET}\n" ; \
	else printf "${WHITE}${NAME}: ${PURPLE}Already cleaned${RESET}\n" ; \
	fi
	make -C inc/ft_printf fclean --no-print-directory

re:	fclean all

.SILENT: norm make_libs clean fclean leaks ${NAME}
.PHONY: all clean fclean re leaks norm
