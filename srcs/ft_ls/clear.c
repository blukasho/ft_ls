/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:54:41 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/23 17:14:20 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				clear_t_ft_ls_dirs(t_ft_ls_dir *dirs)
{
	t_ft_ls_dir	*tmp;

	while (dirs)
	{
		tmp = dirs->next;
		ft_memdel((void **)&dirs);
		dirs = tmp;
	}
}

void				clear_t_ft_ls_data(t_ft_ls_data *data)
{
	if (data->dirs)
		clear_t_ft_ls_dirs(data->dirs);
	ft_memdel((void **)&data);
}
