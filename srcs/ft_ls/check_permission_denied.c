/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_permission_denied.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 11:50:00 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/11 18:32:47 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				check_permission_denied(char *name)
{
	struct stat	sb;
	DIR			*dir;

	dir = ft_open_dir(name);
	if (!lstat(name, &sb) && S_ISDIR(sb.st_mode) && dir && !closedir(dir))
		return (((sb.st_mode & S_IRUSR) ? 0 : 1));
	return (1);
}
