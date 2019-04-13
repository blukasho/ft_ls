/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p_filesize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:41:35 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/13 13:32:40 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*get_p_filesize(t_ft_ls_file *files)
{
	char	*res;
	char	*tmp;
	int		max_len;

	max_len = 0;
	while (files)
	{
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
