# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 20:56:52 by pajimene          #+#    #+#              #
#    Updated: 2024/05/20 21:59:13 by pajimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c \
		  ft_utils.c \
		  
OBJECTS = $(SOURCES:.c=.o)

DEFS = ft_printf.h

all : $(NAME)

$(NAME) : $(OBJECTS) $(DEFS)
		ar rcs $(NAME) $(OBJECTS)

clean :
		rm -rf $(OBJECTS)

fclean : clean
		rm -rf $(NAME)

re : fclean all