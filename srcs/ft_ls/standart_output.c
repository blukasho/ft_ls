/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 22:10:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/04 15:02:44 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					ft_standart_output(t_ft_ls_data *data, char *dir)
{
	DIR				*d;
	t_ft_ls_file	*files;

	if (data)
	{}
	d = ft_open_dir(dir);
	if (d)
	{
		files = read_dir(d);
		clear_t_ft_ls_files(files);
		closedir(d);
	}
	else
		return(error_no_such_file_of_dir(dir));
	return (1);
}
