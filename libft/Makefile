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

NAME	= libft.a

SRCS	= 	ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_memset.c		\
			ft_strlen.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strdup.c		\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strncmp.c	\
			ft_strnstr.c	\
			ft_strtrim.c	\
			ft_split.c		\
			ft_atol.c		\
			ft_calloc.c		\
			ft_strjoin.c	\
			ft_substr.c		\
			ft_itoa.c		\
			ft_strmapi.c	\
			ft_striteri.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_isspace.c	\
			ft_atoi.c		\

SRCSBONUS	=	ft_lstnew_bonus.c		\
				ft_lstadd_front_bonus.c	\
				ft_lstsize_bonus.c		\
				ft_lstlast_bonus.c		\
				ft_lstadd_back_bonus.c	\
				ft_lstdelone_bonus.c	\
				ft_lstclear_bonus.c 	\
				ft_lstiter_bonus.c		\
				ft_lstmap_bonus.c		\

OBJS	= ${patsubst %.c,%.o,${SRCS}}

OBJBONUS = ${patsubst %.c,%.o,${SRCSBONUS}}

D_FILES = ${patsubst %.c,%.d,${SRCS}${SRCSBONUS}}
CFLAGS	= -Wall -Wextra -Werror
OPTFLAGS = -O2

all:	${NAME}

$(NAME): ${OBJS}
		ar rcs ${NAME} $?

%.o : %.c
		gcc ${CFLAGS} ${OPTFLAGS} -c $< -o $@ -MD

include ${wildcard ${D_FILES}}

bonus:
	@make OBJS="${OBJS} ${OBJBONUS}" all
clean:	
	@rm -f ${OBJS} ${OBJBONUS} ${D_FILES}

fclean:	clean
		@rm -f ${NAME}

re:		fclean all

.PHONY:	all clean