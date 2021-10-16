# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldavids <ldavids@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 15:37:27 by ldavids           #+#    #+#              #
#    Updated: 2021/04/27 16:28:00 by ldavids          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of binary file
NAME = checker

# Name of directory
PATH_INC = ../includes/
PATH_SRC = ./
PATH_OBJ = objs/
PATH_LIBFT = ../libft

# List of sources
SRCS = checker.c c_utility00.c c_utility01.c read.c cmds.c\
operators00.c operators01.c operators02.c bonus.c
OBJS = ${addprefix ${PATH_OBJ}, ${SRCS:.c=.o}}
INCS = ${addprefix ${PATH_INC}, header_checker.h}

# Commands of compilation
COMP = gcc
COMP_FLAG = -Wall -Wextra -Werror
COMP_INC = -I ${PATH_INC}

# Others command
RM = /bin/rm

# Color and template code
#YELLOW = \e[38;5;184m
#GREEN = \e[38;5;46m
#RESET = \e[0m
#INFO = [${YELLOW}INFO${RESET}]
#SUCCESS = [${GREEN}OK${RESET}]

# Functions
all :	init ${NAME}
#		@echo "${INFO} Compilation of ${NAME} ${SUCCESS}"

init :
#		@echo "${INFO} Init ${NAME}"
		@${shell mkdir -p ${PATH_OBJ}}
		@make -C ${PATH_LIBFT}

${NAME} : ${OBJS} ${INCS}
		@${CC} ${COMP_FLAG} -o ${NAME} ${OBJS} ${PATH_LIBFT}/libft.a

${PATH_OBJ}%.o : ${PATH_SRC}%.c
		@${COMP} ${COMP_FLAG} ${COMP_INC} -c $< -o $@
		@echo "${INFO} Compilation of $* ${SUCCESS}"

clean :
		@${RM} -rf ${PATH_OBJ}
		@make -C $(PATH_LIBFT) clean;
		@echo "${INFO} Deleted files and directory"

fclean : clean
		@${RM} -rf ${NAME}
		@make -C ${PATH_LIBFT} fclean

re : fclean all

.PHONY : all clean fclean re
