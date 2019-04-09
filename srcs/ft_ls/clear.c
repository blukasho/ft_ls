/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:54:41 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/09 17:09:57 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				clear_t_ft_ls_files(t_ft_ls_file *files)
{
	t_ft_ls_file	*tmp;

	while (files)
	{
		tmp = files->next;
		ft_memdel((void **)&files->filename);
		if (files->permissions)
			ft_memdel((void **)&files->permissions);
		if (files->username)
			ft_memdel((void **)&files->username);
		if (files->groupname)
			ft_memdel((void **)&files->groupname);
		if (files->lastmod)
			ft_memdel((void **)&files->lastmod);
		ft_memdel((void **)&files);
		files = tmp;
	}
}

void				clear_t_ft_ls_data(t_ft_ls_data *data)
{
	if (data->files)
		clear_t_ft_ls_files(data->files);
	ft_memdel((void **)&data);
}
