/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:54:41 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/26 13:52:17 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				clear_t_ft_ls_dirs(t_ft_ls_file *files)
{
	t_ft_ls_file	*tmp;

	while (files)
	{
		tmp = files->next;
		ft_memdel((void **)&files);
		files = tmp;
	}
}

void				clear_t_ft_ls_data(t_ft_ls_data *data)
{
	if (data->files)
		clear_t_ft_ls_dirs(data->files);
	ft_memdel((void **)&data);
}
