/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:34:22 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/09 17:29:56 by blukasho         ###   ########.fr       */
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

static int			check_file(t_ft_ls_file *files, char *name)
{
	while (files)
	{
		if (!ft_strcmp(name, files->filename))
			return (1);
		files = files->next;
	}
	return (0);
}

static t_ft_ls_file	*prepare(t_ft_ls_file *files, char *name, char *path)
{
	char			*full_name;

	full_name = add_path_to_file(path, name);
	files = add_file(files, full_name, path);
	if (!check_file(files, name))
		files = get_t_ft_ls_file(files, name);
	ft_memdel((void **)&full_name);
	return (files);
}

t_ft_ls_file		*read_dir(DIR *d, char *path, t_ft_ls_data *data)
{
	t_ft_ls_file	*files;
	struct dirent	*file;

	files = NULL;
	while ((file = readdir(d)))
		if (data->a)
			files = prepare(files, file->d_name, path);
		else if (file->d_name[0] != '.')
			files = prepare(files, file->d_name, path);
	return (files);
}
