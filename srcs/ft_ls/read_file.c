/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:44:03 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/21 18:39:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char			*remove_path(char *name, char *path)
{
	size_t			i;

	if (path && (i = ft_strlen(path)))
	{
		if (!check_slash(path))
			++i;
		ft_memmove(name, name + i, ft_strlen(name) - i + 1);
	}
	return (name);
}

t_ft_ls_file		*read_file(char *file_name, char *path)
{
	t_ft_ls_file	*file;
	char			*name;
	struct stat		sb;

	name = ft_strdup(file_name);
	name = remove_path(name, path);
	file = get_t_ft_ls_file(NULL, name);
	if (file_name)
		file->full_filename = ft_strdup(file_name);
	ft_memdel((void **)&name);
	if (!lstat(file_name, &sb))
		return (parse_lstat_struct(&sb, file));
	else
		clear_t_ft_ls_files(file);
	return (NULL);
}

t_ft_ls_file		*read_file_link(char *file_name, char *path)
{
	t_ft_ls_file	*file;
	char			*name;
	struct stat		sb;

	name = ft_strdup(file_name);
	name = remove_path(name, path);
	file = get_t_ft_ls_file(NULL, name);
	if (file_name)
		file->full_filename = ft_strdup(file_name);
	ft_memdel((void **)&name);
	if (!stat(file_name, &sb))
		return (parse_lstat_struct(&sb, file));
	else
		clear_t_ft_ls_files(file);
	return (NULL);
}
