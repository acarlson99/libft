# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 14:45:59 by acarlson          #+#    #+#              #
#    Updated: 2018/10/24 20:43:09 by acarlson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
FILES = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower\
ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_itoa ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd\
ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap\
ft_isprime ft_strndup ft_itoabase ft_atoibase ft_strrev ft_isin ft_wordnum ft_wordlen ft_reduce ft_memrealloc ft_floor ft_ceil ft_putflt ft_putdbl ft_abs ft_sqrt ft_numlen ft_strlcpy
LIB_CFILES = $(addsuffix .c, $(FILES))
LIB_OFILES = $(addsuffix .o, $(FILES))
INCLUDES = libft.h
NAME = libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@echo "Compiling $(NAME) object files..."
	@$(CC) $(FLAGS) -I $(INCLUDES) -c $(LIB_CFILES)
	@echo "Linking $(NAME) object files..."
	@ar rc $(NAME) $(LIB_OFILES)
	@ranlib libft.a

clean:
	@echo "Removing $(NAME) object files..."
	@/bin/rm -f $(LIB_OFILES)

fclean: clean
	@echo "Removing $(NAME)..."
	@/bin/rm -f $(NAME)

re: fclean all
