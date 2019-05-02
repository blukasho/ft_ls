/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:59:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/02 17:40:18 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void			*print_error_files(t_ft_ls_file *files)
{
	while (files)
	{
		if (!is_file(files->filename) && !is_dir(files->filename))	
			error_no_such_file_of_dir(files->filename);
		files = files->next;
	}
	return (NULL);
}

int					ft_ls(int argc, char **argv)
{
	t_ft_ls_data	*data;
	t_ft_ls_file	*tmp;

	if((data = ft_read_args(argc, argv)))
	{
		data->files = sort(data->files, data);
		print_error_files(data->files);
		tmp = data->files;
		while (data->files)
		{
			start_print_result(data, data->files->filename);
			data->files = data->files->next;
		}
		data->files = tmp;
		clear_t_ft_ls_data(data);
	}
	else
		print_usage();
	return (0);
}
