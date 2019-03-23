/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:26:05 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/23 15:51:17 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ft_ls_dir			*get_t_ft_ls_dir(t_ft_ls_dir *dirs, char *s)
{
	t_ft_ls_dir		*new;
	t_ft_ls_dir		*tmp;

	new = (t_ft_ls_dir *)malloc(sizeof(t_ft_ls_dir));
	ft_bzero(new, sizeof(t_ft_ls_dir));
	new->dir = s;
	if (dirs)
	{
		tmp = dirs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		return (dirs);
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
