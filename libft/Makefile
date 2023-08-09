# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabertha <pabertha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 17:16:25 by pabertha          #+#    #+#              #
#    Updated: 2023/07/07 17:15:06 by pabertha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \

SRC_BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)
# norminette -R CheckForbiddenSourceHeader *.c

$(NAME) : $(OBJ)
		ar rcs $(NAME) $(OBJ)

bonus : $(OBJ) $(OBJ_BONUS)
		ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

%.o : %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
