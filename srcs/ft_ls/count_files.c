/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:40:48 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/11 12:44:43 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

size_t		count_files(t_ft_ls_file *files)
{
	size_t	len;

	len = 0;
	while (files)
	{
		files = files->next;
		++len;
	}
	return (len);
}
