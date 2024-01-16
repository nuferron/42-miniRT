# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 00:01:43 by nuferron          #+#    #+#              #
#    Updated: 2024/01/16 19:46:33 by nuferron         ###   ########.fr        #
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

SRCS =	ft_dprintf.c printf_char.c printf_string.c printf_num.c \
		printf_unsigned_num.c printf_pointers.c printf_hex_cap.c \
		printf_hex_min.c

OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))

OBJDIR = obj/
SRCDIR = src/
NAME = libftprintf.a
INC = inc/
CFLAGS = -Wall -Wextra -Werror
COLUMNS = $(shell tput cols)

all:		${NAME}

${NAME}:	${OBJS}
		ar rcs ${NAME} ${OBJS}
		printf "${WHITE}FT_DPRINTF: ${GREEN}Library compiled!${RESET}\n"

norm:
	printf "${WHITE}FT_DPRINTF${RESET}"
	(norminette ${SRCDIR} && echo " ${GREEN}All good")  | grep -v "OK" \
	| awk '{if($$2 == "Error!") print "\n${RED}"$$1" "$$2; \
	else print "${RESET}"$$0}'

${OBJDIR}%.o:	${SRCDIR}%.c ${INC} | ${OBJDIR}
		@printf "${WHITE}FT_DPRINTF:${CYAN}Compiling files: ${WHITE}$(notdir $<)...${RESET}\r"
		@cc $(CFLAGS) -I $(INC) -c $< -o $@
		@printf "\r%-${COLUMNS}s\r" ""

${OBJDIR}:
		mkdir -p $(dir $@)

clean:
	if [ -d ${OBJDIR} ] ; then \
		rm -rf ${OBJDIR} ${OBJDIR_BNS} ; \
		printf "${WHITE}FT_DPRINTF: ${RED}Objects have been deleted${RESET}\n" ; \
	fi

fclean: 	clean
		if [ -e ${NAME} ] ; then \
			rm -rf ${NAME} ; \
			printf "${WHITE}FT_DPRINTF: ${RED}Static library has been deleted${RESET}\n" ; \
		else printf "${WHITE}FT_DPRINTF: ${PURPLE}Already cleaned${RESET}\n" ; \
		fi

re:	fclean all

.SILENT: ${NAME} ${OBJDIR} clean fclean ${OBJDIR_BNS} do_bonus make_libs norm
.PHONY: all clean fclean re bonus
