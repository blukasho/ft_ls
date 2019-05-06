/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_only_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:48:03 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/06 15:30:59 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_ft_ls_file	*add(t_ft_ls_file *files, t_ft_ls_file *file)
{
	t_ft_ls_file	*res;

	res = files;
	while (files->next)
		files = files->next;
	files->next = file;
	return (res);
}

static t_ft_ls_file	*get_files(t_ft_ls_file *old_files)
{
	t_ft_ls_file	*new_files;

	new_files = NULL;
	while (old_files)
	{
		if (is_file(old_files->filename) && !is_dir(old_files->filename))
		{
			if (new_files)
				new_files = add(new_files, read_file(old_files->filename, NULL));
			else
				new_files = read_file(old_files->filename, NULL);
		}
		old_files = old_files->next;
	}
	return (new_files);
}

int					print_only_files(t_ft_ls_data *data)
{
	t_ft_ls_file	*files;

	files = get_files(data->files);
	if (data->l)
		print_long_format_files(files);
	clear_t_ft_ls_files(files);
	return (0);
}
