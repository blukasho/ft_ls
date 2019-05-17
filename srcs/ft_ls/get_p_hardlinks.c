/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p_hardlinks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:07:55 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/17 13:47:21 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*get_p_hardlinks(t_ft_ls_file *files)
{
	char	*res;
	char	*tmp;
	int		max_len;

	max_len = 0;
	while (files)
	{
		if (ft_len_of_digit(files->hardlinks) > max_len)
			max_len = ft_len_of_digit(files->hardlinks);
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
