/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_other_files.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:05:21 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/11 18:07:43 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void				split_other_files(t_ft_ls_file *files)
{
	t_ft_ls_file	*tmp;

	if (files->next && files->next->next)
	{
		tmp = files->next->next;
		files->next->next = tmp->next;
		tmp->next = files->next;
		files->next = tmp;
	}
}
