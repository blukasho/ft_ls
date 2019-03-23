/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 22:10:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/23 22:59:52 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					ft_standart_ountput(char *dir)
{
	DIR				*d;
	struct dirent	*s;
	int				sw;

	d = ft_open_dir(dir);
	if (d && !(sw = 0))
	{
		while ((s = readdir(d)))
		{
			if (sw)
				ft_printf(" ");
			ft_printf("%s", s->d_name);
			sw = 1;
		}
		ft_printf("\n");
		closedir(d);
	}
	else
		return(error_no_such_file_of_dir(dir));
	return (1);
}
