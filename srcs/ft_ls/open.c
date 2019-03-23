/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 14:15:57 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/23 15:53:41 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_open_dir(char *path)
{
	DIR		*d;
	
	if (path)
	{
		d = opendir(path);
		if (d)
			ft_printf("dir %s\n", path);
		else
			ft_printf("ERROR");
	}
	else
	{
		d = opendir(".");
		if (d)
			ft_printf("dir .\n");
		else
			ft_printf("ERROR");
	}
	if (d)
		ft_printf("%d\n", d);
}
