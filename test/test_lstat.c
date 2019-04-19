/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:06:31 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/19 16:21:46 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define FP_SPECIAL 1
#define STR_SIZE sizeof("rwxrwxrwx")

#define _BSD_MACHINE_SOURCE
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

char			*filePermStr(mode_t perm, int flags)
{
	static char	str[STR_SIZE];

	(perm & S_IRUSR) ? strcat(str, "r") : strcat(str, "-");
	(perm & S_IWUSR) ? strcat(str, "w") : strcat(str, "-");
	(perm & S_IXUSR) ?
		(((perm & S_ISUID) && (flags & FP_SPECIAL)) ? strcat(str, "s") :
		 strcat(str, "x")) :
		(((perm & S_ISUID) && (flags & FP_SPECIAL)) ? strcat(str, "S") :
		 strcat(str, "-"));
	(perm & S_IRGRP) ? strcat(str, "r") : strcat(str, "-");
	(perm & S_IWGRP) ? strcat(str, "w") : strcat(str, "-");
	(perm & S_IXGRP) ?
		(((perm & S_ISGID) && (flags & FP_SPECIAL)) ? strcat(str, "s") :
		 strcat(str, "x")) :
		(((perm & S_ISGID) && (flags & FP_SPECIAL)) ? strcat(str, "S") :
		 strcat(str, "-"));
	(perm & S_IROTH) ? strcat(str, "r") : strcat(str, "-");
	(perm & S_IWOTH) ? strcat(str, "w") : strcat(str, "-");
	(perm & S_IXOTH) ?
		(((perm & S_ISVTX) && (flags & FP_SPECIAL)) ? strcat(str, "t") :
		 strcat(str, "x")) :
		(((perm & S_ISVTX) && (flags & FP_SPECIAL)) ? strcat(str, "T") :
		 strcat(str, "-"));
	return (str);
}

void				displayUserGroup(struct stat *sb)
{
	struct passwd	*user;
	struct group	*group;

	group = getgrgid(sb->st_gid);
	user = getpwuid(sb->st_uid);
	printf("User name %s, Group name %s\n", user->pw_name, group->gr_name);
}

void			displayStatInfo(struct stat *sb)
{
	printf("File type : ");
	if (S_ISREG(sb->st_mode))
		printf("regular file.\n");
	else if (S_ISDIR(sb->st_mode))
		printf("directory.\n");
	else if (S_ISCHR(sb->st_mode))
		printf("character device.\n");
	else if (S_ISBLK(sb->st_mode))
		printf("block device.\n");
	else if (S_ISLNK(sb->st_mode))
		printf("symbolic (soft) link.\n");
	else if (S_ISFIFO(sb->st_mode))
		printf("FIFO or pipe.\n");
	else if (S_ISSOCK(sb->st_mode))
		printf("socket.\n");
	else
		printf("uknown file type.\n");

	printf("Device containing i-node: major=%ld minor=%ld\n",
			(long)major(sb->st_dev), (long)minor(sb->st_dev));

	printf("I-node number: %ld\n", (long) sb->st_ino);

	printf("Mode: %lo (%s)\n", (unsigned long) sb->st_mode, filePermStr(sb->st_mode, FP_SPECIAL));

	if (sb->st_mode & (S_ISUID | S_ISGID | S_ISVTX))
		printf("Special bits set : %s%s%s\n",
				(sb->st_mode & S_ISUID) ? "set-UID " : "",
				(sb->st_mode & S_ISGID) ? "set-GID " : "",
				(sb->st_mode & S_ISVTX) ? "sticky " : "");

	printf("Number of (hard) links: %ld\n", (long)sb->st_nlink);

	printf("Ownership: UID=%ld GID=%ld\n", (long)sb->st_uid, (long)sb->st_gid);

	displayUserGroup(sb);

  if (S_ISCHR(sb->st_mode) || S_ISBLK(sb->st_mode))
  	printf("Device number (st_rdev) : major=%ld; minor=%#.8lx\n",
  			(long)major(sb->st_rdev), (long)minor(sb->st_rdev));

	printf("File size: %lld bytes\n", (long long)sb->st_size);
	printf("Optimal I/O block size: %ld bytes\n", (long)sb->st_blksize);
	printf("512B blocks allocated: %lld\n", (long long)sb->st_blocks);
	printf("Last file access: %s", ctime(&sb->st_atime));
	printf("Last file modification: %s", ctime(&sb->st_mtime));
	printf("Last status change: %s", ctime(&sb->st_ctime));
}

int				main(int argc, char **argv)
{
	struct stat	sb;
	int			statLink;
	int 		fname;

	statLink = (argc > 1) && strcmp(argv[1], "-1") == 0;

	fname = statLink ? 2 : 1;

	if (fname >= argc || (argc > 1 && strcmp(argv[1], "--help") == 0))
		printf("Usage\n");

	if (statLink)
	{
		if (lstat(argv[fname], &sb) == -1)
			return (printf("Error in lstat\n"));
		printf("Use lstat OK.\n");
	}
	else
	{
		if (stat(argv[fname], &sb) == -1)
			return (printf("Error in stat\n"));
		printf("Use stat OK.\n");
	}
	displayStatInfo(&sb);
	return (0);
}
