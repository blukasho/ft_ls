/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:51:49 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/20 17:14:05 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				is_dir(char *dirname)
{
	struct stat	sb;

	if (!lstat(dirname, &sb) && S_ISDIR(sb.st_mode))
		return (1);
	return (0);
}
