/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p_username.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:41:48 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/13 10:49:47 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*get_p_username(t_ft_ls_file *files)
{
	char	*res;
	char	*tmp;
	size_t	max_len;

	max_len = 0;
	while (files)
	{
		if (files->username && ft_strlen(files->username) > max_len)
			max_len = ft_strlen(files->username);
		files = files->next;
	}
	tmp = ft_itoa(max_len);
	res = ft_strjoin("%-", tmp);
	ft_memdel((void **)&tmp);
	tmp = res;
	res = ft_strjoin(res, "s  ");
	ft_memdel((void **)&tmp);
	return (res);
}
