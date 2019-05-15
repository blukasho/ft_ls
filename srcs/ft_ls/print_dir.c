/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:30:29 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/15 15:51:41 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	check_exep(t_ft_ls_data *data, t_ft_ls_file *files)
{
	if (data->t && !files->filetype)
		return (1);
	return (0);
}

static int	check_exep_dir(char *dirname)
{
	if (!ft_strcmp(".", dirname))
		return (1);
	else if (!ft_strcmp("..", dirname))
		return (1);
	return (0);
}

int			print_dir(t_ft_ls_data *data, t_ft_ls_file *files, char *dirname)
{
	if (data->print_dir_name)
		ft_printf("%s:\n", dirname);
	if (files && data->l && !check_exep(data, files))
		print_long_format_dir(files);
	else if (files && !check_exep(data, files))
		print_normal_format_files(files);
	if (data->rr)
		while (files)
		{
			data->print_dir_name = 1;
			if (files->filetype == 'd' && !check_exep_dir(files->filename))
			{
				ft_printf("\n");
				standart_output_dir(data, files->full_filename);
			}
			files = files->next;
		}
	return (0);
}
