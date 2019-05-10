/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 17:29:05 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/10 12:42:13 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ft_ls_file		*sort_by_reverse(t_ft_ls_file *files)
{
	t_ft_ls_file	*prev;
	t_ft_ls_file	*curr;
	t_ft_ls_file	*next;

	curr = files;
	files = NULL;
	prev = NULL;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return (prev);
}
