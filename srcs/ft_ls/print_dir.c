/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:30:29 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/09 18:37:16 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int	check_exep(t_ft_ls_data *data, t_ft_ls_file *files)
{
	if (data->t && !files->filetype)
		return (1);
	return (0);
}

int			print_dir(t_ft_ls_data *data, t_ft_ls_file *files)
{
	if (files && data->l && !check_exep(data, files))
		print_long_format_dir(files);
	else if (files && !check_exep(data, files))
		print_normal_format_files(files);
	return (0);
}
