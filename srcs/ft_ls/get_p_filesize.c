/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p_filesize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:41:35 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/18 17:47:09 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	get_major_minor_len(t_ft_ls_file *file)
{
	int		major;
	int		minor;

	if (file->filetype == 'c' || file->filetype == 'b')
	{
		major = ft_len_of_digit(file->major);
		minor = ft_len_of_digit(file->minor);
		return (major + minor + 2);
	}
	return (0);
}

char		*get_p_filesize(t_ft_ls_file *files)
{
	char	*res;
	char	*tmp;
	int		max_len;

	max_len = 0;
	while (files)
	{
		if (get_major_minor_len(files) > max_len)
			max_len = get_major_minor_len(files);
		if (ft_len_of_digit(files->filesize) > max_len)
			max_len = ft_len_of_digit(files->filesize);
		files = files->next;
	}
	tmp = ft_itoa(max_len);
	res = ft_strjoin("%", tmp);
	ft_memdel((void **)&tmp);
	tmp = res;
	res = ft_strjoin(res, "lld ");
	ft_memdel((void **)&tmp);
	return (res);
}
