/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparate_files_to_output.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:38:08 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/21 18:36:45 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	*preparate_files_to_output(t_ft_ls_file *files)
{
	while (files)
	{
		if (!is_file(files->filename) && !is_dir(files->filename))
			error_no_such_file_of_dir(files->filename);
		files = files->next;
	}
	return (NULL);
}
