/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 16:39:41 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/23 22:19:43 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		error_invalid_flag(char f)
{
	ft_printf("ft_ls: invalid option -- '%c'\n", f);
	return (0);
}

int		error_no_such_file_of_dir(char *dir)
{
	ft_printf("ft_ls: cannot access '%s': No such file or directory\n", dir);
	return (0);
}
