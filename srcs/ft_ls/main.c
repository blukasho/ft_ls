/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:10:02 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/23 12:01:34 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					main(int argc, char **argv)
{
	t_ft_ls_data	*data;
	t_ft_ls_file	*tmp;

	--argc;
	++argv;
	if((data = ft_read_args(argc, argv)))
	{
		preparate_files_to_output(data->files);
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
//	system("leaks ft_ls");
	return (0);
}
