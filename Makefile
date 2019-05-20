# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blukasho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/31 12:56:17 by blukasho          #+#    #+#              #
#*   Updated: 2019/05/18 16:37:06 by blukasho         ###   ########.fr       *#
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
	   additional_functions_1.c ft_int_arr_mult.c ft_int_arr_subtr.c\
	   ft_sum_two_digits.c ft_pos_exp_of_digit.c ft_neg_exp_of_digit.c\
	   ft_int_arr_comparing.c ft_print_int_arr.c additional_functions_double.c\
	   t_sum_two_digits_del.c check_period.c ft_sum.c ft_get_double_bits.c\
	   ft_get_double_exp.c ft_get_double_man.c convert_double.c round_double.c\
	   ft_print_double_bits.c ft_len_of_digit.c\

SRCS_FT_LS = clear.c error.c init_structs.c open.c print.c read_args.c\
			 standart_output.c usage.c read_dir.c read_file.c\
			 parse_lstat_struct.c get_file_type.c get_file_permissions.c\
			 add_path_to_file.c check_slash.c sort_by_name.c count_files.c\
			 split_head_files.c split_other_files.c get_p_filesize.c\
			 get_p_hardlinks.c get_p_username.c get_p_group.c is_dir.c\
			 get_p_major_minor.c sort.c sort_by_time.c is_file.c ft_ls.c\
			 print_long_format_files.c print_long_format_dir.c total.c\
			 sort_by_reverse.c check_permission_denied.c print_only_files.c\
			 print_normal_format_files.c print_dir.c has_dir.c check_ea.c\
			 check_acl.c
			 

FT_LS = ft_ls

vpath %.c srcs srcs/ft_printf srcs/ft_ls

OBJ = $(SRCS:.c=.o)

OBJ_LS = $(SRCS_FT_LS:.c=.o)

FLAGS = -Wall -Wextra -Werror -I includes

FT_LS_MAIN = srcs/ft_ls/main.c

LIBFT = libft.a

all: $(FT_LS)

$(FT_LS): $(LIBFT) $(FT_LS_MAIN)
	gcc $(FLAGS) $(FT_LS_MAIN) $(LIBFT) -o $(FT_LS)

$(LIBFT): $(OBJ) $(OBJ_LS)
	ar -rv $(LIBFT) $^
	ranlib $(LIBFT)

$(OBJ_LS): %.o: %.c
	gcc $(FLAGS) -c $< -o $@

$(OBJ): %.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean: 
	rm -rf $(OBJ)
	rm -rf $(OBJ_LS)

fclean: clean
	rm -rf $(FT_LS)
	rm -rf $(LIBFT)

re:	fclean all

.PHONY: all clean fclean re
