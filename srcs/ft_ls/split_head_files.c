/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_head_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:02:59 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/11 18:05:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_ft_ls_file		*split_head_files(t_ft_ls_file *files)
{
	t_ft_ls_file	*head;

	head = files->next;
	files->next = head->next;
	head->next = files;
	return (head);
}
