/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format_files.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 14:37:51 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/17 13:50:41 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					print_long_format_files(t_ft_ls_file *files)
{
	t_print			*p;

	p = get_t_print(files);
	while (files)
	{
		ft_printf("%c", files->filetype);
		ft_printf("%-11s", files->permissions);
		ft_printf(p->p_hardlinks, files->hardlinks);
		ft_printf(p->p_username, files->username);
		ft_printf(p->p_group, files->groupname);
		if (files->filetype == 'c' || files->filetype == 'b')
			ft_printf(p->p_major_minor, files->major, files->minor);
		else
			ft_printf(p->p_filesize, files->filesize);
		ft_printf("%.24s ", files->lastmod);
		ft_printf("%s", files->filename);
		if (files->filetype == 'l')
			ft_printf(" -> %s", files->link_file);
		ft_printf("\n");
		files = files->next;
		if (!files)
			return (clear_t_print(p));
	}
	return (0);
}
