# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 14:45:59 by acarlson          #+#    #+#              #
#    Updated: 2018/11/15 12:54:09 by acarlson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
INCLUDES = includes/
LIB_FILES = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp\
		ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strncat\
		ft_strlcat ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp\
		ft_strncmp ft_atoi ft_isalpha ft_isdigit ft_isalnum ft_isascii\
		ft_isprint ft_toupper ft_tolower\
		\
		ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr ft_striter\
		ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub\
		ft_strjoin ft_strtrim\ ft_strsplit ft_itoa ft_putchar ft_putstr\
		ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd ft_putendl_fd\
		ft_putnbr_fd\
		\
		ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap\
		\
		get_next_line\
		\
		ft_isprime ft_strndup ft_itoabase ft_atoibase ft_strrev ft_isin\
		ft_wordnum ft_wordlen ft_reduce ft_memrealloc ft_floor ft_ceil\
		ft_putflt ft_putflt_fd ft_putdbl ft_putdbl_fd ft_abs ft_sqrt ft_snumlen\
		ft_unumlen ft_strlcpy ft_round ft_swap\ ft_strchri ft_lstrev\
		ft_lstadd_tail ft_strspn ft_strcspn ft_putchar_fd_2 ft_putdbl_fd_2\
		ft_putendl_fd_2 ft_putflt_fd_2 ft_putnbr_base_2 ft_putnbr_fd_2\
		ft_putstr_fd_2 ft_putnstr_fd ft_putcstr_fd ft_atosize_tbase\
		ft_size_ttoabase ft_ssize_ttoabase ft_wcharlen ft_putwchar_fd\
		ft_wstrlen ft_putwstr ft_putnwstr
LIB_CFILES = $(addsuffix .c, $(LIB_FILES))
LIB_OFILES = $(addsuffix .o, $(LIB_FILES))
LIB_NAME = libft.a

PF_SRCS = ft_printf_srcs/
PF_FILES = ft_printf disp print_str_char print_int print_unsigned print_oct\
		print_hex print_pointer print_percent print_padding parse_input\
		find_options print_bin find_colors
PF_CFILES = $(addprefix $(PF_SRCS), $(addsuffix .c, $(PF_FILES)))
PF_OFILES = $(addsuffix .o, $(PF_FILES))

.PHONY: all clean fclean re

all: $(LIB_NAME) printf

clean:
	@echo "Removing $(LIB_NAME) object files"
	@/bin/rm -f $(LIB_OFILES)
	@echo "Removing printf object files"
	@/bin/rm -f $(PF_OFILES)

fclean: clean
	@echo "Removing $(LIB_NAME)"
	@/bin/rm -f $(LIB_NAME)

re: fclean all

lib: $(LIB_NAME)

$(LIB_NAME):
	@echo "Compiling $(LIB_NAME) object files"
	@$(CC) $(FLAGS) -c $(LIB_CFILES) -I $(INCLUDES)
	@echo "Linking $(LIB_NAME) object files"
	@ar rc $(LIB_NAME) $(LIB_OFILES)
	@ranlib $(LIB_NAME)

lib_clean:
	@echo "Removing $(LIB_NAME) object files"
	@/bin/rm -f $(LIB_OFILES)

lib_fclean: lib_clean
	@echo "Removing $(LIB_NAME)..."
	@/bin/rm -f $(LIB_NAME)

lib_re: lib_fclean $(LIB_NAME)

relib: lib_re

printf: lib
	@echo "Compiling printf object files"
	@$(CC) $(FLAGS) -I $(INCLUDES) -c $(PF_CFILES)
	@echo "Linking printf object files with $(LIB_NAME)"
	@ar rc $(LIB_NAME) $(PF_OFILES)

pf_clean:
	@echo "Removing $(PF_NAME) object files"
	@/bin/rm -f $(PF_OFILES)

pf_fclean: pf_clean
	@echo "Removing $(PF_NAME)"
	@/bin/rm -f $(PF_NAME)

pf_re: pf_fclean printf
