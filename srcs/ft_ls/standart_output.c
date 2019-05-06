/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 22:10:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/06 12:07:42 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					standart_output_dir(t_ft_ls_data *data, char *dir)
{
	DIR				*d;
	t_ft_ls_file	*files;

	d = ft_open_dir(dir);
	if (d)
	{
		files = read_dir(d, dir);
		files = sort(files, data);
		print_long_format_dir(files);
		clear_t_ft_ls_files(files);
		closedir(d);
		return (1);
	}
	else if (check_permission_denied(dir))
	{
		error_permission_denied(dir);
		return (1);
	}
	return (0);
}

int					standart_output_file(t_ft_ls_data *data, char *file_name)
{
	t_ft_ls_file	*file;

	if (data && (file = read_file(file_name, NULL)))
	{
		print_long_format_files(file);
		clear_t_ft_ls_files(file);
		return (1);
	}
	return (0);
}

int					ft_standart_output(t_ft_ls_data *data, char *dir)
{
	if (standart_output_dir(data, dir))
		return (1);
	else if (standart_output_file(data, dir))
		return (1);
	return (0);
}
