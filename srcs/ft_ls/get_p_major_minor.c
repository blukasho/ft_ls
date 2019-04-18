/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p_major_minor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:27:57 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/18 17:54:37 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	*get_result(int major, int minor)
{
	char	*res;
	char	*tmp;
	char	*tmp2;

	tmp = ft_itoa(major);
	res = ft_strjoin("%", tmp);
	ft_memdel((void **)&tmp);
	tmp = res;
	res = ft_strjoin(res, "ld, %");
	ft_memdel((void **)&tmp);
	tmp = ft_itoa(minor);
	tmp2 = res;
	res = ft_strjoin(res, tmp);
	ft_memdel((void **)&tmp);
	ft_memdel((void **)&tmp2);
	tmp = res;
	res = ft_strjoin(res, "ld ");
	ft_memdel((void **)&tmp);
	return (res);
}

char		*get_p_major_minor(t_ft_ls_file *files)
{
	char	*res;
	int		major;
	int		minor;

	major = 0;
	minor = 0;
	while (files)
	{
		if (files->filetype == 'c' || files->filetype == 'b')
		{
			if (ft_len_of_digit(files->major) > major)
				major = ft_len_of_digit(files->major);
			if (ft_len_of_digit(files->minor) > minor)
				minor = ft_len_of_digit(files->minor);
		}
		files = files->next;
	}
	res = get_result(major, minor);
	return (res);
}
