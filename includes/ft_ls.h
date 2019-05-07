/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:28:07 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/07 17:18:10 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define PERM_SIZE sizeof("rwxrwxrwx")
# define LINK_FILE PATH_MAX
# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <dirent.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>

typedef struct				s_ft_ls_file
{
	long					major;
	long					minor;
	char					*link_file;
	char					*full_filename;
	char					*filename;
	char					*permissions;
	long					hardlinks;
	char					*username;
	char					*groupname;
	long					inode;
	long long				filesize;
	long long				blocks;
	char					*lastmod;
	long					time_stamp;
	unsigned char			filetype;
	struct s_ft_ls_file		*next;
}							t_ft_ls_file;

typedef struct				s_ft_ls_data
{
	int						l;
	int						a;
	int						r;
	int						t;
	int						rr;
	t_ft_ls_file			*files;
}							t_ft_ls_data;

typedef struct				s_print
{
	char					*p_hardlinks;
	char					*p_filesize;
	char					*p_username;
	char					*p_group;
	char					*p_major_minor;
}							t_print;

unsigned char				get_file_type(struct stat *sb);

char						*add_path_to_file(char *path, char *file);
char						*get_file_permissions(mode_t perm);
char						*get_p_filesize(t_ft_ls_file *files);
char						*get_p_hardlinks(t_ft_ls_file *files);
char						*get_p_username(t_ft_ls_file *files);
char						*get_p_group(t_ft_ls_file *files);
char						*get_p_major_minor(t_ft_ls_file *files);

size_t						count_files(t_ft_ls_file *files);

__int128					get_total(t_ft_ls_file *files);

t_print						*get_t_print(t_ft_ls_file *files);

t_ft_ls_file				*sort_by_reverse(t_ft_ls_file *files);
t_ft_ls_file				*sort_by_time(t_ft_ls_file *files);
t_ft_ls_file				*sort_by_name(t_ft_ls_file *files);
t_ft_ls_file				*sort(t_ft_ls_file *file, t_ft_ls_data *data);
t_ft_ls_file				*split_head_files(t_ft_ls_file *files);
t_ft_ls_file				*parse_lstat_struct(struct stat *sb, t_ft_ls_file *file);
t_ft_ls_file				*read_file(char *file_name, char *path);
t_ft_ls_file				*read_dir(DIR *d, char *path);
t_ft_ls_file				*add_file(t_ft_ls_file *files, char *file, char *path);
t_ft_ls_file				*get_t_ft_ls_file(t_ft_ls_file *files, char *s);
t_ft_ls_data				*ft_read_args(int ar, char **av);
t_ft_ls_data				*get_t_ft_ls_data(void);

int							check_permission_denied(char *name);
int							print_normal_format_files(t_ft_ls_file *files);
int							print_long_format_dir(t_ft_ls_file *files);
int							print_long_format_files(t_ft_ls_file *files);
int							print_only_files(t_ft_ls_data *data);
int							ft_ls(int argc, char **argv);
int							is_dir(char *dirname);
int							is_file(char *filename);
int							check_slash(char *path);
int							standart_output_file(t_ft_ls_data *data, char *file);
int							standart_output_dir(t_ft_ls_data *data, char *dir);
int							ft_read_flags(char *flags, t_ft_ls_data *data);
int							error_permission_denied(char *dir);
int							error_no_such_file_of_dir(char *file);
int							error_invalid_flag(char f);
int							ft_standart_output(t_ft_ls_data *data, char *dir);

void						split_other_files(t_ft_ls_file *files);
void						start_print_result(t_ft_ls_data *data, char *name);
void						print_usage(void);

void						*clear_t_ft_ls_data(t_ft_ls_data *data);
void						*clear_t_ft_ls_files(t_ft_ls_file *files);
void						clear_t_print(t_print *p);

DIR							*ft_open_dir(char *path);

#endif
