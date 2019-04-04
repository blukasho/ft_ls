/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:34:22 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/04 15:08:04 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

unsigned char		get_file_type(unsigned char f)
{
	if (f == DT_BLK)
		return ('b');
	else if (f == DT_CHR)
		return ('c');
	else if (f == DT_DIR)
		return ('d');
	else if (f == DT_LNK)
		return ('l');
	else if (f == DT_SOCK)
		return ('s');
	else if (f == DT_FIFO)
		return ('p');
	else if (f == DT_REG)
		return ('-');
	return (0);
}

t_ft_ls_file		*add_file(t_ft_ls_file *files, struct dirent *file)
{
	t_ft_ls_file	*tmp;

	files = get_t_ft_ls_file(files, file->d_name);
	tmp = files;
	while (files)
  	{
		if (!ft_strcmp(files->filename, file->d_name))
			files->filetype = get_file_type(file->d_type);
		files = files->next;
	}
	return (tmp);
}

t_ft_ls_file		*read_dir(DIR *d)
{
	t_ft_ls_file	*files;
	struct dirent	*file;

	files = NULL;
	while ((file = readdir(d)))
		files = add_file(files, file);
	print_files(files);
	return (files);
}
