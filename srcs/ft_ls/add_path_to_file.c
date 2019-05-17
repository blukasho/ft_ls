/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path_to_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:26:57 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/17 18:26:02 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*add_path_to_file(char *path, char *file)
{
	char	*tmp;
	char	*res;

	if (!check_slash(path))
	{
		tmp = ft_strjoin(path, "/");
		res = ft_strjoin(tmp, file);
		ft_memdel((void **)&tmp);
	}
	else
		res = ft_strjoin(path, file);
	return (res);
}
