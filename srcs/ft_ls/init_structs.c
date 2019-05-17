/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:26:05 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/17 13:44:32 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ft_ls_file		*get_t_ft_ls_file(t_ft_ls_file *files, char *s)
{
	t_ft_ls_file	*new;
	t_ft_ls_file	*tmp;

	new = (t_ft_ls_file *)malloc(sizeof(t_ft_ls_file));
	ft_bzero(new, sizeof(t_ft_ls_file));
	new->filename = ft_strdup(s);
	new->next = NULL;
	if (files)
	{
		tmp = files;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		return (files);
	}
	else
		return (new);
}

t_ft_ls_data		*get_t_ft_ls_data(void)
{
	t_ft_ls_data	*data;

	data = (t_ft_ls_data *)malloc(sizeof(t_ft_ls_data));
	ft_bzero(data, sizeof(t_ft_ls_data));
	return (data);
}

t_print				*get_t_print(t_ft_ls_file *files)
{
	t_print			*res;

	res = (t_print *)malloc(sizeof(t_print));
	res->p_filesize = get_p_filesize(files);
	res->p_hardlinks = get_p_hardlinks(files);
	res->p_username = get_p_username(files);
	res->p_group = get_p_group(files);
	res->p_major_minor = get_p_major_minor(files);
	return (res);
}
