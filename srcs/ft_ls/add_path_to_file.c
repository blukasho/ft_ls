/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path_to_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:26:57 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/10 17:53:18 by blukasho         ###   ########.fr       */
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
		return (res);
	}
	else
		return (ft_strjoin(path, file));
	return (NULL);
}
