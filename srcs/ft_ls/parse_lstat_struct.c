/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lstat_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:05:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/09 17:36:05 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char			*get_username(struct stat *sb)
{
	struct passwd	*user;

	user = getpwuid(sb->st_uid);
	return (ft_strdup(user->pw_name));
}

static char			*get_groupname(struct stat *sb)
{
	struct group	*group;

	group = getgrgid(sb->st_gid);
	return (ft_strdup(group->gr_name));
}

static char			*get_lastmod(struct stat *sb)
{
	return (ft_strdup(ctime(&sb->st_mtime)));
}

t_ft_ls_file		*parse_lstat_struct(struct stat *sb, t_ft_ls_file *file)
{
	if (sb && file)
	{
		file->filetype = get_file_type(sb);
		file->permissions = get_file_permissions(sb->st_mode);
		file->hardlinks = (long)sb->st_nlink;
		file->username = get_username(sb);
		file->groupname = get_groupname(sb);
		file->filesize = (long long)sb->st_size;
		file->lastmod = get_lastmod(sb);
		ft_printf("%c%s %2ld %s %s %lld %.16s %s\n", file->filetype, file->permissions,
				file->hardlinks, file->username, file->groupname,
				file->filesize, file->lastmod, file->filename);
		return (file);
	}
	return (NULL);
}
