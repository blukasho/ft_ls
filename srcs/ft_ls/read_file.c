/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:44:03 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/09 14:12:44 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ft_ls_file		*read_file(char *file_name)
{
	struct stat		sb;
	t_ft_ls_file	*file;

	file = get_t_ft_ls_file(NULL, file_name);
	if (!lstat(file_name, &sb))
		return (parse_lstat_struct(&sb, file));
	else
		clear_t_ft_ls_files(file);
	return(NULL);
}
