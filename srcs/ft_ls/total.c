/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:22:17 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/02 15:30:05 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

__int128		get_total(t_ft_ls_file *files)
{
	__int128	total;

	total = 0;
	while (files)
	{
		total += files->blocks;
		files = files->next;
	}
	return (total);
}
