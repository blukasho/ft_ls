# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blukasho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 12:56:17 by blukasho          #+#    #+#              #
#*   Updated: 2019/03/23 13:49:32 by blukasho         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRCS = ft_bzero.c ft_memcpy.c ft_memset.c ft_memccpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	   ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
	   ft_strrchr.c ft_strcmp.c ft_strstr.c ft_strncmp.c ft_strnstr.c\
	   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	   ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c\
	   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
	   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
	   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c\
	   ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
	   ft_putendl_fd.c ft_putnbr_fd.c ft_count_words.c ft_lstnew.c\
	   ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c\
	   ft_strndup.c ft_get_arr.c ft_is_lower.c ft_is_upper.c ft_is_space.c\
	   get_next_line.c ft_strlen_chr.c ft_printf.c ft_printf_parser.c\
	   parse_flags.c result_preparation.c print_char.c print_pointer.c\
	   print_digits.c print_octal.c additional_functions.c\
	   print_unsigned_digits.c print_hexdecimal.c print_double.c\
	   print_percent.c print_string.c main_function.c check_errors.c\
	   reverse_double.c additional_functions_1.c additional_functions_2.c\
	   ft_int_arr_mult.c ft_int_arr_subtr.c ft_len_of_digit.c\
	   ft_sum_two_digits.c ft_pos_exp_of_digit.c ft_neg_exp_of_digit.c\
	   ft_int_arr_comparing.c ft_print_int_arr.c additional_functions_double.c\

vpath %.c srcs srcs/ft_printf srcs/ft_ls

DIR_O = tmp

OBJ = $(addprefix $(DIR_O)/,$(SRCS:.c=.o))

FLAGS = -Wall -Wextra -g3 -I includes

NAME = libft.a

FT_LS = ft_ls

all: $(DIR_O) $(NAME) $(FT_LS)

$(FT_LS): $(NAME) ft_ls.c
	gcc $(FLAGS) srcs/ft_ls/ft_ls.c -o $(FT_LS) $(NAME)

$(DIR_O):
	mkdir -p tmp

$(NAME): $(OBJ)
	ar -rv $(NAME) $^
	ranlib $(NAME)

$(OBJ): $(DIR_O)/%.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean: 
	rm -rf $(DIR_O)

fclean: clean
	rm -rf $(FT_LS)
	rm -rf $(NAME)
	rm -rf a.out
	rm -rf a.out.dSYM

re:	fclean all

.PHONY: all clean fclean re
