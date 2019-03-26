/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 13:28:31 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/26 12:20:44 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	--argc;
	++argv;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			++j;
		}
		++i;
	}
	i = 0;
	while (i < argc)
		ft_printf("%s\n", argv[i++]);
	return (0);
}
