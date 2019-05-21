/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_only_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:48:03 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/21 17:38:37 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_ft_ls_file	*add(t_ft_ls_file *files, t_ft_ls_file *file)
{
	t_ft_ls_file	*res;

	res = files;
	if (files)
	{
		while (files->next)
			files = files->next;
		files->next = file;
	}
	else
		res = file;
	return (res);
}

static t_ft_ls_file	*get_files(t_ft_ls_data *data)
{
	t_ft_ls_file	*n_files;
	t_ft_ls_file	*o_files;

	n_files = NULL;
	o_files = data->files;
	while (o_files)
	{
		if (o_files->filetype != 'd')
		{
			if (data->a)
				n_files = add(n_files, read_file(o_files->filename, NULL));
			else if (*(o_files->filename) != '.')
				n_files = add(n_files, read_file(o_files->filename, NULL));
		}
		o_files = o_files->next;
	}
	return (n_files);
}

int					print_only_files(t_ft_ls_data *data)
{
	t_ft_ls_file	*files;

	files = get_files(data);
	if (files && data->l)
	{
		print_long_format_files(files);
		clear_t_ft_ls_files(files);
		return (1);
	}
	else if (files)
	{
		print_normal_format_files(files);
		clear_t_ft_ls_files(files);
		return (1);
	}
	clear_t_ft_ls_files(files);
	return (0);
}
