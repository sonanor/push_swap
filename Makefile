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

SRCS	= 	commands/push.c				\
			commands/reverse_rotate.c	\
			commands/rotate.c			\
			commands/swap.c				\
			helpers/sorting_helpers.c	\
			helpers/sorting_helpers_2.c	\
			helpers/utils.c				\
			helpers/validation.c		\
			parser/init_lists.c			\
			parser/parser.c				\
			sorting/minimal_sorting.c	\
			sorting/primary_sorting.c	\
			sorting/secondary_sorting.c	\
			sorting/sorting.c			\
			push_swap.c					\
			sorting/butterfly.c			\


OBJ		=	$(SRCS:%.c=%.o)

LIB		=	libft/libft.a

INCLUDE	=	include/

HEADER	=	push_swap.h

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

libft:
			@$(MAKE) -C libft/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)
			@echo "$(TURQUOISE)\n\t Complited $(NAME) \n$(END)"

%.o:		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)

#bonus:		libft $(OBJ_B)
#			$(CC) $(FLAGS) $(OBJ_B) $(LIB) -o $(NAME_B)
#			@echo "$(TURQUOISE)\n\tComplited $(NAME_B) \n$(END)"

clean:
			@$(RM) $(OBJ)
			@$(MAKE) -C libft/ clean
			@echo "$(BLUE)\n\tCleaning succeed\n$(END)"

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(RM) $(NAME)
			@echo "$(BLUE)\tAll files were deleted\n$(END)"

re:			fclean all
			@echo "$(BLUE)\tRemake done\n$(END)"
