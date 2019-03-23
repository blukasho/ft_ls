/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standart_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 22:10:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/23 22:37:06 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			ft_standart_ountput(char *dir)
{
	DIR		*d;

	d = ft_open_dir(dir);
	if (d)
	{
		ft_printf("Open successfully.\n");
		closedir(d);
	}
	else
		return(error_no_such_file_of_dir(dir));
	return (1);
}
