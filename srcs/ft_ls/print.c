/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 21:40:37 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/04 15:08:35 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	start_print_result(t_ft_ls_data *data, char *dir)
{
	if (data->R)
		ft_printf("Print recursively.\n");
	else
		ft_standart_output(data, dir);
}

void	print_files(t_ft_ls_file *files)
{
	while (files)
	{
		ft_printf("file type %c file name %s\n", files->filetype, files->filename);
		files = files->next;
	}
}
