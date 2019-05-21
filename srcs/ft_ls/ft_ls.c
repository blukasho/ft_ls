/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:59:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/21 18:31:24 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					ft_ls(int argc, char **argv)
{
	t_ft_ls_data	*data;
	t_ft_ls_file	*files;

	if ((data = ft_read_args(argc, argv)))
	{
		data->files = sort(data->files, data);
		files = data->files;
		print(data);
		clear_t_ft_ls_data(data);
		clear_t_ft_ls_files(files);
	}
	else
		print_usage();
	return (0);
}
