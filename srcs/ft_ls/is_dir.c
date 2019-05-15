/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:51:49 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/15 15:45:06 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					is_dir(char *dirname)
{
	t_ft_ls_file	*file;

	if ((file = read_file(dirname, NULL)) && file->filetype == 'd')
	{
		clear_t_ft_ls_files(file);
		return (1);
	}
	clear_t_ft_ls_files(file);
	return (0);
}
