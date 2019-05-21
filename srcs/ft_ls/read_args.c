/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 15:01:04 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/21 18:39:48 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_ft_ls_file	*add_new_file(t_ft_ls_file *files, t_ft_ls_file *file)
{
	t_ft_ls_file	*tmp;

	tmp = files;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = file;
	}
	else
		return (file);
	return (files);
}

static t_ft_ls_data	*add_dir(char *file, t_ft_ls_data *data)
{
	t_ft_ls_file	*new_file;

	if (is_link(file) && !data->l)
		new_file = read_file_link(file, NULL);
	else
		new_file = read_file(file, NULL);
	if (new_file)
		data->files = add_new_file(data->files, new_file);
	else
		data->files = get_t_ft_ls_file(data->files, file);
	return (data);
}

int					ft_read_flags(char *flags, t_ft_ls_data *data)
{
	int				i;

	i = 0;
	if (ft_strcmp(flags, "-") && flags[i] == '-')
	{
		while (flags[++i])
		{
			if (flags[i] == 'l')
				data->l = 1;
			else if (flags[i] == 'a')
				data->a = 1;
			else if (flags[i] == 'r')
				data->r = 1;
			else if (flags[i] == 't')
				data->t = 1;
			else if (flags[i] == 'R')
				data->rr = 1;
			else
				return (error_invalid_flag(flags[i]));
		}
	}
	else
		add_dir(flags, data);
	return (1);
}

t_ft_ls_data		*ft_read_args(int ar, char **av)
{
	int				i;
	t_ft_ls_data	*data;

	i = -1;
	data = get_t_ft_ls_data();
	if (*av && ar == 1 && !ft_strcmp(*av, "--"))
		return (add_dir(".", data));
	if (*av && !ft_read_flags(av[0], data))
		return (clear_t_ft_ls_data(data));
	else
		++i;
	while (++i < ar)
		add_dir(av[i], data);
	if (!data->files)
		ft_read_flags(".", data);
	return (data);
}
