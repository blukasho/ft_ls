/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:23:53 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/09 14:34:59 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

unsigned char	get_file_type(struct stat *sb)
{
	if (S_ISREG(sb->st_mode))
		return ('-');
	else if (S_ISDIR(sb->st_mode))
		return ('d');
	else if (S_ISCHR(sb->st_mode))
		return ('c');
	else if (S_ISBLK(sb->st_mode))
		return ('b');
	else if (S_ISLNK(sb->st_mode))
		return ('l');
	else if (S_ISFIFO(sb->st_mode))
		return ('p');
	else if (S_ISSOCK(sb->st_mode))
		return ('s');
	return (0);
}
