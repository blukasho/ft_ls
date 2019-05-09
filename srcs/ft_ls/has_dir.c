/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 11:56:56 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/09 12:27:04 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		has_dir(t_ft_ls_file *files)
{
	while (files)
	{
		if (files->filetype == 'd')
			return (1);
		files = files->next;
	}
	return (0);
}
