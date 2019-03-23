/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:10:02 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/23 23:00:20 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					main(int argc, char **argv)
{
	t_ft_ls_data	*data;
	t_ft_ls_dir		*tmp;

	--argc;
	++argv;
	if((data = ft_read_args(argc, argv)))
	{
		tmp = data->dirs;
		while (data->dirs)
		{
			start_print_result(data, data->dirs->dir);
			data->dirs = data->dirs->next;
		}
		data->dirs = tmp;
		clear_t_ft_ls_data(data);
	}
	else
		print_usage();
	return (0);
}
