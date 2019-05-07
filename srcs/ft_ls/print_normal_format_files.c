/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_normal_format_files.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:13:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/07 17:21:23 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			print_normal_format_files(t_ft_ls_file *files)
{
	while (files)
	{
		ft_printf("%s", files->filename);
		if (files->next)
			ft_printf(" ");
		files = files->next;
	}
	ft_printf("\n");
	return (0);
}
