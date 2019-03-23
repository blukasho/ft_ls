/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 17:24:22 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/23 17:34:58 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_usage(void)
{
	ft_printf("Use this options:\n");
	ft_printf("%10s %s\n", "-l", "use a long listing format");
	ft_printf("%10s %s\n", "-a", "do not ignore entries starting with .");
	ft_printf("%10s %s\n", "-r", "reverse order while sorting");
	ft_printf("%10s %s\n", "-t", "sort by modification time, newest first");
	ft_printf("%10s %s\n", "-R", "list subdirectories recursively");
}
