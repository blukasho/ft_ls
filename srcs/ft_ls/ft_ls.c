/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 13:59:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/09 10:36:32 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					ft_ls(int argc, char **argv)
{
	t_ft_ls_data	*data;
	t_ft_ls_file	*files;

	if((data = ft_read_args(argc, argv)))
	{
		files = data->files;
		data->files = sort(data->files, data);
		print(data);
		data->files = files;
		clear_t_ft_ls_data(data);
	}
	else
		print_usage();
	return (0);
}
