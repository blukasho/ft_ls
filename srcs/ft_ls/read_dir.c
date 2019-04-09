/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:34:22 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/09 18:06:37 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

//need add pathname to correct read files in path
t_ft_ls_file		*add_file(t_ft_ls_file *files, struct dirent *file)
{
	t_ft_ls_file	*tmp;

	tmp = files;
	if (files)
	{
		while (files->next)
			files = files->next;
		files->next = read_file(file->d_name);
	}
	else
		return (read_file(file->d_name));
	return (tmp);
}

t_ft_ls_file		*read_dir(DIR *d)
{
	t_ft_ls_file	*files;
	struct dirent	*file;

	files = NULL;
	while ((file = readdir(d)))
		files = add_file(files, file);
//	print_files(files);
	return (files);
}
