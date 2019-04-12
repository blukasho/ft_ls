/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_readlink.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:51:52 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/12 11:58:59 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <sys/stat.h>
#include <limits.h>

#define	BUFF_SIZE PATH_MAX

int			main(int argc, char **argv)
{
	char	buf[BUFF_SIZE];
	int		len_buf;

	--argc;
	++argv;
	if (argc == 1)
	{
		if ((len_buf = readlink(argv[0], buf, BUFF_SIZE - 1)) == -1)
			return(ft_printf("Error read link.\n"));
		buf[len_buf] = '\0';
		ft_printf("%s -> %s\n", argv[0], buf);
	}
	return (0);
}
