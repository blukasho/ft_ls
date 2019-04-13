/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 21:40:37 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/13 13:32:39 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	start_print_result(t_ft_ls_data *data, char *dir)
{
	if (data->rr)
		ft_printf("Print recursively.\n");
	else
		ft_standart_output(data, dir);
}

void		print_files(t_ft_ls_file *files)
{
	t_print	*p;

	p = get_t_print(files);
	while (files)
	{
		ft_printf("%c", files->filetype);
		ft_printf("%s  ", files->permissions);
		ft_printf(p->p_hardlinks, files->hardlinks);
		ft_printf(p->p_username, files->username);
		ft_printf(p->p_group, files->groupname);
		ft_printf(p->p_filesize, files->filesize);
		ft_printf("%.24s ", files->lastmod);
		ft_printf("%s ", files->filename);
		if (files->filetype == 'l')
			ft_printf("-> %s", files->link_file);
		ft_printf("\n");
		files = files->next;
	}
	clear_t_print(p);
}
