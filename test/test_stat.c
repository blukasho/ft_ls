/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:24:36 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/21 16:31:17 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"
#include <sys/stat.h>

int				main(int argc, char **argv)
{
	struct stat	sb;
	int			i;

	--argc;
	++argv;
	if (argc)
	{
		i = stat(*argv, &sb);	
		ft_printf("stat() return value vith %s  = %d\n", *argv, i);
	}
	else
		ft_printf("\n");
	return (0);
}
