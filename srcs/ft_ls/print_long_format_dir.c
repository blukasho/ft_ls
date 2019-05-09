/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long_format_dir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:15:11 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/09 18:21:14 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				print_long_format_dir(t_ft_ls_file *files)
{
	__int128	total;

	if (files && files->filetype)
	{
		total = get_total(files);
		ft_printf("total %lld\n", total);
		print_long_format_files(files);
	}
	return (0);
}
