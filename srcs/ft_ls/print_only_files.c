/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_only_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:32:51 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/03 15:03:04 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					print_only_files(t_ft_ls_data *data)
{
	t_ft_ls_file	*files;

	files = data->files;
	while (files)
	{
//		if (files->filetype == 'd')
//		{
//			if (data->l)
//			{
//				print_long_format_file(data->files, files);
//			}
//			else
//			{
//				ft_printf("%s", files->filename);
//			}
//			if (files->next)
//			{
//				ft_printf(" ");
//			}
//		}
		files = files->next;
	}
	return (0);
}
