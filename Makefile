# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nzhuzhle <nzhuzhle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 16:44:50 by nuferron          #+#    #+#              #
#    Updated: 2024/02/22 21:43:44 by nuferron         ###   ########.fr        #
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

SRCS_MLX = mlx.c draw.c
SRCS_INPUT = check_input.c init_scene.c init_utils.c init_objects.c \
translation.c
SRCS_UTILS = num_utils.c utils.c mem_utils.c math_utils.c
SRCS_OPER = vector_utils.c vector_utils2.c vector_utils3.c
SRCS_INTERSEC = plane_intersect.c sphere_intersect.c ray_intersect.c \
cylinder_intersect.c
SRCS_SCREEN = screen.c color_utils.c

SRCS = 	$(addprefix input/,$(SRCS_INPUT)) \
		$(addprefix utils/,$(SRCS_UTILS)) \
		$(addprefix mlx/,$(SRCS_MLX)) \
		$(addprefix operations/,$(SRCS_OPER)) \
		$(addprefix intersect/,$(SRCS_INTERSEC)) \
		$(addprefix screen/,$(SRCS_SCREEN)) \
		main.c
SRCDIR = src/
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
OBJDIR = obj/
NAME = miniRT
CFLAGS = -Wall -Wextra -Werror -O3 -fsanitize=address
LIB = inc/libft/libft.a inc/ft_dprintf/libftprintf.a
INC = inc/
MLXFLAGS = -Linc/mlx -lmlx -framework OpenGL -framework AppKit
COLUMNS = $(shell tput cols)
TEST = tests/test.rt

all: make_libs ${NAME}

make_libs:
	make -C inc/libft bonus --no-print-directory
	make -C inc/ft_dprintf --no-print-directory
	@make -s -C inc/mlx --no-print-directory 2> /dev/null

${NAME}: ${OBJS} ${LIB}
	cc ${CFLAGS} ${LIB} ${OBJS} ${MLXFLAGS} -o ${NAME}
	echo "${WHITE}${NAME}: ${GREEN}Binary successfully created!${RESET}"

norm:
	make -C inc/libft norm --no-print-directory
	make -C inc/ft_dprintf norm --no-print-directory
	printf "${WHITE}${NAME}${RESET}"
	(norminette ${SRCDIR} && echo " ${GREEN}All good")  | grep -v "OK" \
	| awk '{if($$2 == "Error!") print "\n${RED}"$$1" "$$2; \
	else print "${RESET}"$$0}'

leaks: ${NAME}
	leaks -atExit -- ./${NAME} ${MAP}

run: ${NAME}
	./${NAME} ${TEST}

${OBJDIR}%.o: ${SRCDIR}%.c ${HEADER} Makefile
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
	make -C inc/ft_dprintf clean --no-print-directory

fclean: 	clean
	if [ -e ${NAME} ] ; then \
		rm -f ${NAME} ${LIB} do_bonus ; \
		printf "${WHITE}${NAME}: ${RED}All existing binaries have been deleted${RESET}\n" ; \
	else printf "${WHITE}${NAME}: ${PURPLE}Already cleaned${RESET}\n" ; \
	fi
	make -C inc/libft fclean --no-print-directory
	make -C inc/ft_dprintf fclean --no-print-directory
	@make -s -C inc/mlx clean --no-print-directory

re:	fclean all

.SILENT: norm clean fclean leaks make_libs ${NAME} run
.PHONY: all clean fclean re leaks norm run
