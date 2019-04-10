/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:34:22 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/10 17:56:22 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ft_ls_file		*add_file(t_ft_ls_file *files, char *file, char *path)
{
	t_ft_ls_file	*tmp;

	tmp = files;
	if (files)
	{
		while (files->next)
			files = files->next;
		files->next = read_file(file, path);
	}
	else
		return (read_file(file, path));
	return (tmp);
}

t_ft_ls_file		*read_dir(DIR *d, char *path)
{
	char			*full_name;
	t_ft_ls_file	*files;
	struct dirent	*file;

	files = NULL;
	while ((file = readdir(d)))
	{
		full_name = add_path_to_file(path, file->d_name);
		files = add_file(files, full_name, path);
		ft_memdel((void **)&full_name);
	}
	return (files);
}
