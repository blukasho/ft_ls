/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:27:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/21 18:38:41 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int			check_split(t_ft_ls_file *files)
{
	if (files && files->next)
		if (ft_strcmp(files->filename, files->next->filename) > 0)
			return (1);
	return (0);
}

t_ft_ls_file		*sort_by_name(t_ft_ls_file *files)
{
	t_ft_ls_file	*start;
	size_t			i;

	i = 1;
	while (i && !(i = 0))
		if (check_split(files) && ++i)
			files = split_head_files(files);
		else
		{
			start = files;
			while (start)
			{
				if (check_split(start->next) && ++i)
					split_other_files(start);
				start = start->next;
			}
			start = NULL;
		}
	return (files);
}
