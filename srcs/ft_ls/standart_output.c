/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 22:10:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/26 15:10:38 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					ft_standart_ountput(char *dir)
{
	DIR				*d;
	struct dirent	*s;

	d = ft_open_dir(dir);
	if (d)
	{
		while ((s = readdir(d)))
		{
			ft_printf("%s\n", s->d_name);
		}
		closedir(d);
	}
	else
		return(error_no_such_file_of_dir(dir));
	return (1);
}
