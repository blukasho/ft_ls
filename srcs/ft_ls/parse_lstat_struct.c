/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lstat_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:05:54 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/17 13:21:45 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char			*get_username(struct stat *sb)
{
	struct passwd	*user;

	user = getpwuid(sb->st_uid);
	if (user)
		return (ft_strdup(user->pw_name));
	return (NULL);
}

static char			*get_groupname(struct stat *sb)
{
	struct group	*group;

	group = getgrgid(sb->st_gid);
	if (group)
		return (ft_strdup(group->gr_name));
	return (NULL);
}

static char			*get_lastmod(struct stat *sb)
{
	long			curr_time;
	char			*lastmod;
	int				move;

	lastmod = ft_strdup(ctime(&sb->st_mtime));
	curr_time = (long)time(NULL);
	move = (curr_time - (long)sb->st_mtime > HALF_YEAR ? 1 : 0);
	ft_memmove(lastmod, lastmod + 4, ft_strlen(lastmod + 3));
	lastmod[ft_strlen(lastmod) - 1] = '\0';
	if (move)
		ft_memmove(lastmod + 7, lastmod + 15, 6);
	else
		lastmod[12] = '\0';
	return (lastmod);
}

static char			*get_link_file(t_ft_ls_file *file)
{
	int				len;

	file->link_file = ft_strnew(LINK_FILE);
	len = readlink(file->full_filename, file->link_file, LINK_FILE - 1);
	if (len == -1)
	{
		ft_memdel((void **)&(file->link_file));
		return (NULL);
	}
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
		file->permissions = get_file_permissions(sb->st_mode, file);
		file->hardlinks = (long)sb->st_nlink;
		file->username = get_username(sb);
		file->groupname = get_groupname(sb);
		file->filesize = (long long)sb->st_size;
		file->blocks = (long long)sb->st_blocks;
		file->lastmod = get_lastmod(sb);
		file->inode = (long)sb->st_ino;
		file->major = (long)major(sb->st_rdev);
		file->minor = (long)minor(sb->st_rdev);
		file->time_stamp = (long)sb->st_mtime;
		return (file);
	}
	return (NULL);
}
