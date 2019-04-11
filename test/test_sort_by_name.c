/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_by_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 15:14:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/11 17:57:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int			check_split(t_ft_ls_file *files)
{
	if (files && files->next)
		if (ft_strcmp(files->filename, files->next->filename) > 0)
			return (1);
	return (0);
}

static t_ft_ls_file	*split_head(t_ft_ls_file *files)
{
	t_ft_ls_file	*head;

	head = files->next;
	files->next = head->next;
	head->next = files;
	return (head);
}

static void			sort_other(t_ft_ls_file *files)
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

static t_ft_ls_file	*ft_sort_by_name(t_ft_ls_file *files)
{
	t_ft_ls_file	*start;
	int				i;

	i = 1;
	while (i && !(i = 0))
		if (check_split(files) && ++i)
			files = split_head(files);
		else
		{
			start = files;
			while (start)
			{
				if (check_split(start->next) && ++i)
					sort_other(start);
				start = start->next;
			}
		}
	return (files);
}

int					main(int argc, char **argv)
{
	t_ft_ls_file	*files;

	--argc;
	++argv;
	if (argc)
		while (--argc >= 0)
			files = get_t_ft_ls_file(files, argv[argc]);
	ft_printf("--------->>>>>>>>>>>Unsorted files.\n");
	print_files(files);
	files = ft_sort_by_name(files);
	ft_printf("--------->>>>>>>>>>>Sorted files.\n");
	print_files(files);
	clear_t_ft_ls_files(files);
	return (0);
}
