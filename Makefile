# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adratini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 18:40:27 by adratini          #+#    #+#              #
#    Updated: 2021/10/09 18:40:29 by adratini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
NAME_B	= checker

SRCS_SHARE	= 	commands/push.c				\
			commands/reverse_rotate.c	\
			commands/rotate.c			\
			commands/swap.c				\
			helpers/sorting_helpers.c	\
			helpers/utils.c				\
			helpers/validation.c		\
			helpers/helpers.c			\
			parser/init_lists.c			\
			parser/parser.c				\
			sorting/minimal_sorting.c	\
			sorting/sorting.c			\
			sorting/butterfly.c

SRCS_MANDATORY = push_swap.c

SRCS_BONUS	= bonus/bonus_checker.c		\
				gnl/get_next_line.c			\
				gnl/get_next_line_utils.c	\

OBJ_M		=	$(SRCS_MANDATORY:.c=.o)
OBJ_S		=	$(SRCS_SHARE:.c=.o)
OBJ_B	=	$(SRCS_BONUS:.c=.o)

LIB		=	libft/libft.a

HEADER_SRCS		=	push_swap.h
HEADER_BONUS	=	bonus/bonus_checker.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf

#---------------------------------------------------------------------------------
RED		=	\033[1;31m
BLUE	=	\033[1;34m
YELLOW	=	\033[1;33m
WHITE	=	\033[1;32m
PUPURE	=	\033[1;35m
GRY		=	\033[1;30m
TURQUOISE =	\033[36;1m
END		=	\033[0m
#---------------------------------------------------------------------------------


.PHONY:		all	clean	fclean	re	bonus	libft

all:		libft $(NAME)

%.o:		%.c
			$(CC) $(FLAGS)  -c $< -o $@

libft:
			@$(MAKE) -C libft/

$(NAME):	$(OBJ_S) $(OBJ_M) $(HEADER_SRCS) libft
			$(CC) $(FLAGS) $(OBJ_S) $(OBJ_M) $(LIB) -o $(NAME)
			@echo "$(TURQUOISE)\n\t Completed $(NAME) \n$(END)"



bonus:		$(OBJ_S) $(OBJ_B) $(HEADER_SRCS) $(HEADER_BONUS) libft
			$(CC) $(FLAGS) $(OBJ_S) $(OBJ_B) $(LIB) -o $(NAME_B)
			@echo "$(TURQUOISE)\n\tCompleted $(NAME_B) \n$(END)"


clean:
			@$(RM) $(OBJ_S) $(OBJ_B)  $(OBJ_M)
			@$(MAKE) -C libft/ clean
			@echo "$(BLUE)\n\tCleaning succeed\n$(END)"

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME) $(NAME_B)
			@echo "$(BLUE)\tAll files were deleted\n$(END)"

re:			fclean all
			@echo "$(BLUE)\tRemake done\n$(END)"
