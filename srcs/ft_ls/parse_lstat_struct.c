/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lstat_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:05:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/19 16:31:22 by blukasho         ###   ########.fr       */
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

static char			*get_link_file(t_ft_ls_file *file)
{
	int				len;

	file->link_file = ft_strnew(LINK_FILE);
	len = readlink(file->full_filename, file->link_file, LINK_FILE - 1);
	file->link_file[len] = '\0';
	return (file->link_file);
}

t_ft_ls_file		*parse_lstat_struct(struct stat *sb, t_ft_ls_file *file)
{
	if (sb && file)
	{
		file->filetype = get_file_type(sb);
		if (file->filetype == 'l')
			file->link_file = get_link_file(file);
		file->permissions = get_file_permissions(sb->st_mode);
		file->hardlinks = (long)sb->st_nlink;
		file->username = get_username(sb);
		file->groupname = get_groupname(sb);
		file->filesize = (long long)sb->st_size;
		file->lastmod = get_lastmod(sb);
		file->inode = (long)sb->st_ino;
		file->major = (long)major(sb->st_rdev);
		file->minor = (long)minor(sb->st_rdev);
		file->time_stamp = (long)sb->st_mtime;
		return (file);
	}
	return (NULL);
}
