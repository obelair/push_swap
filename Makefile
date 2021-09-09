# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelair <obelair@student.42Lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 15:45:01 by obelair           #+#    #+#              #
#    Updated: 2021/07/31 15:45:01 by obelair          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# === Name === #

NAME_PUSH	=	push_swap
NAME_CHECK	=	checker

# === Directories === #

PATH_LIBFT	=	libft
PATH_HEADERS=	incs
PATH_SRCS	=	srcs
PATH_OBJS	=	objs


# === Compil === #

CC			=	gcc
RENAME_PSW	=	-o ${NAME_PUSH}
RENAME_CHK	=	-o ${NAME_CHECK}
CFLAGS		=	-Wall -Werror -Wextra -g3 #-fsanitize=address#
INCS		=	-I${PATH_HEADERS} -I${PATH_LIBFT}/${PATH_HEADERS}
LIBS		=	${PATH_LIBFT}/libft.a
RM			=	rm -rf

# === Sources === #

SRCS		=	${addprefix ${PATH_SRCS}/, error.c parsing.c init.c chunk.c sort.c find.c comp.c use.c insert.c \
					push.c swap.c rotate.c rev_rotate.c \
					stack_new.c stack_last.c stack_size.c stack_clear.c stack_add.c}
SRCS_PUSH	=	${addprefix ${PATH_SRCS}/, main.c algo.c radix.c}
SRCS_CHECK	=	${addprefix ${PATH_SRCS}/, checker.c}

# === Objects === #

OBJS_PUSH	=	${addprefix ${PATH_OBJS}/, ${notdir ${SRCS_PUSH:.c=.o}} ${notdir ${SRCS:.c=.o}}}
OBJS_CHECK	=	${addprefix ${PATH_OBJS}/, ${notdir ${SRCS_CHECK:.c=.o}} ${notdir ${SRCS:.c=.o}}}

# === Include === #

HEADERS		=	${addprefix ${PATH_HEADERS}/, push_swap.h utils.h}

# === Colors === #

_END		=	\033[0m
_BOLD		=	\033[1m
_DIM		=	\033[2m
_UNDERLINE	=	\033[3m

_RED		=	\033[31m
_GREEN		=	\033[32m
_YELLOW		=	\033[33m
_CYAN		=	\033[36m
_LIGHTGRAY	=	\033[37m
_DARKGRAY	=	\033[90m
_LIGHTRED	=	\033[91m

# === Default === #

all:	init ${NAME_PUSH} ${NAME_CHECK}

# === Commands === #

${PATH_OBJS}/%.o: ${PATH_SRCS}/%.c ${HEADERS}
	@ echo " ${_GREEN}${_DIM}\\\\\ ${_END}${_GREEN}Compilation done!${_DIM} //${_CYAN}   --->   ${_END}${_YELLOW}| ${_BOLD}${_CYAN}$<${_END} "
	@ ${CC} ${CFLAGS} -c $< -o $@ ${INCS}

bonus:	all ${NAME_CHECK}

init:	
	@ ${shell mkdir -p ${PATH_OBJS}}
	@ ${MAKE} -C ${PATH_LIBFT}

${NAME_PUSH}: ${OBJS_PUSH} ${PATH_LIBFT}/libft.a
	@ echo "\n${_LIGHTRED}${_BOLD}${_DIM}$?${_END}\n" \
		"\t ${_YELLOW}${_DIM}${_BOLD}Add to ${NAME_PUSH}!${_END} \n"
	@ ${CC} ${RENAME_PSW} ${CFLAGS} ${OBJS_PUSH} ${LIBS}

${NAME_CHECK}: ${OBJS_CHECK} ${PATH_LIBFT}/libft.a ${NAME_PUSH}
	@ echo "\n${_LIGHTRED}${_BOLD}${_DIM}$?${_END}\n" \
		"\t ${_YELLOW}${_DIM}${_BOLD}Add to ${NAME_CHECK}!${_END} \n"
	@ ${CC} ${RENAME_CHK} ${CFLAGS} ${OBJS_CHECK} ${LIBS}

# === Clean === #

clean:	
	@echo "${_LIGHTRED}${_DIM}.o files clean!${_END}"
	@ ${MAKE} clean -C ${PATH_LIBFT}
	@ ${RM} ${PATH_OBJS}

fclean :	clean
	@ echo "${_LIGHTRED}${_DIM}${NAME_PUSH} / ${NAME_CHECK} clean!${_END}"
	@ ${MAKE} fclean -C ${PATH_LIBFT}
	@ ${RM} ${NAME_PUSH} ${NAME_CHECK}

re :	fclean all

.PHONY :	all clean fclean re bonus init