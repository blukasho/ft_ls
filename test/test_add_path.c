/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_add_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:37:15 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/10 12:33:41 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	check_slash(char *path)
{
	while (*path)
		++path;
	return (*(path - 1) == '/' ? 1 : 0);
}

char		*add_path_to_file(char *path, char *file)
{
	char	*tmp;
	char	*res;

	if (!check_slash(path))
	{
		tmp = ft_strjoin(path, "/");
		res = ft_strjoin(tmp, file);
		ft_memdel((void **)&tmp);
		return (res);
	}
	else
		return (ft_strjoin(path, file));
	return (NULL);
}

int			main(int argc, char **argv)
{
	char	*s;
	--argc;
	++argv;
	if (argc == 2)
	{
		s = add_path_to_file(argv[0], argv[1]);
		ft_printf("Result ->|%s|\n", s);
		ft_memdel((void **)&s);
	}
	else
		ft_printf("First parm path, last param file.\n");
	return (0);
}
