/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:30:29 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/09 13:05:20 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		print_dir(t_ft_ls_data *data, t_ft_ls_file *files)
{
	if (files && data->l)
		print_long_format_dir(files);
	else if (files)
		print_normal_format_files(files);
	return (0);
}
