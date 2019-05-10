/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:35:05 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/10 19:42:29 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ft_ls_file	*sort(t_ft_ls_file *files, t_ft_ls_data *data)
{
	if (data->t)
		files = sort_by_time(files);
	else
		files = sort_by_name(files);
	if (data->r)
		files = sort_by_reverse(files);
	return (files);
}
