/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format_file.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:28:55 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/03 14:33:33 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			print_long_format_file(t_ft_ls_file *files, t_ft_ls_file *file)
{
	t_print	*p;

	p = get_t_print(files);
	ft_printf("%c", file->filetype);
	ft_printf("%s  ", file->permissions);
	ft_printf(p->p_hardlinks, file->hardlinks);
	ft_printf(p->p_username, file->username);
	ft_printf(p->p_group, file->groupname);
	if (file->filetype == 'c' || file->filetype == 'b')
		ft_printf(p->p_major_minor, file->major, file->minor);
	else
		ft_printf(p->p_filesize, file->filesize);
	ft_printf("%.24s ", file->lastmod);
	ft_printf("%s ", file->filename);
	if (file->filetype == 'l')
		ft_printf("-> %s", file->link_file);
	return (0);
}
