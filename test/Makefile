# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blukasho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 12:14:03 by blukasho          #+#    #+#              #
#*   Updated: 2019/04/10 10:43:12 by blukasho         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

all:
	gcc -fsanitize=address -g3 test_sort_by_name.c ../libft.a
	./a.out | cat -e

fclean:
	rm -rf a.out
	rm -rf a.out.dSYM
