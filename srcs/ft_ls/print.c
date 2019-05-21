/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 21:40:37 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/21 18:37:55 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	print_error_files(t_ft_ls_file *files)
{
	int		i;

	i = 0;
	while (files)
	{
		if (!is_file(files->filename) && !is_dir(files->filename) && (i = 1))
			error_no_such_file_of_dir(files->filename);
		files = files->next;
	}
	return (i);
}

void		start_print_result(t_ft_ls_data *data, char *name)
{
	ft_standart_output(data, name);
}

int			print(t_ft_ls_data *data)
{
	int		f;

	print_error_files(data->files);
	f = print_only_files(data);
	if (f && has_dir(data->files))
		ft_printf("\n");
	while (data->files)
	{
		if (data->files->filetype == 'd')
		{
			if (data->files->next || f)
				data->print_dir_name = 1;
			start_print_result(data, data->files->filename);
			if (has_dir(data->files->next))
				ft_printf("\n");
			f = 1;
		}
		data->files = data->files->next;
	}
	return (0);
}
