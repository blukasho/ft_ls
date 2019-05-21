/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:46:53 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/21 18:33:08 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					is_file(char *filename)
{
	t_ft_ls_file	*file;

	if ((file = read_file(filename, NULL)) && !clear_t_ft_ls_files(file))
		return (1);
	return (0);
}
