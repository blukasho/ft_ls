/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:54:41 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/13 10:00:14 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				*clear_t_ft_ls_files(t_ft_ls_file *files)
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
		if (files->full_filename)
			ft_memdel((void **)&files->full_filename);
		if (files->link_file)
			ft_memdel((void **)&files->link_file);
		ft_memdel((void **)&files);
		files = tmp;
	}
	return (NULL);
}

void				*clear_t_ft_ls_data(t_ft_ls_data *data)
{
	if (data->files)
		clear_t_ft_ls_files(data->files);
	ft_memdel((void **)&data);
	return (NULL);
}

int					clear_t_print(t_print *p)
{
	if (p->p_filesize)
		ft_memdel((void **)&p->p_filesize);
	if (p->p_hardlinks)
		ft_memdel((void **)&p->p_hardlinks);
	if (p->p_username)
		ft_memdel((void **)&p->p_username);
	if (p->p_group)
		ft_memdel((void **)&p->p_group);
	if (p->p_major_minor)
		ft_memdel((void **)&p->p_major_minor);
	ft_memdel((void **)&p);
	return (1);
}
