/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:28:07 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/04 13:41:30 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>

typedef struct				s_ft_ls_file
{                           
	char					*filename;
	unsigned char			filetype;
	struct s_ft_ls_file		*next;
}							t_ft_ls_file;

typedef struct				s_ft_ls_data
{                           
	int						l;
	int						a;
	int						r;
	int						t;
	int						R;
	t_ft_ls_file			*files;
}							t_ft_ls_data;

unsigned char				get_file_type(unsigned char f);

t_ft_ls_file				*read_dir(DIR *d);
t_ft_ls_file				*add_file(t_ft_ls_file *files, struct dirent *file);
t_ft_ls_file				*get_t_ft_ls_file(t_ft_ls_file *files, char *s);
                            
t_ft_ls_data				*ft_read_args(int ar, char **av);
t_ft_ls_data				*get_t_ft_ls_data(void);

int							ft_read_flags(char *flags, t_ft_ls_data *data);
int							error_no_such_file_of_dir(char *file);
int							error_invalid_flag(char f);
int							ft_standart_output(t_ft_ls_data *data, char *dir);

void						print_files(t_ft_ls_file *files);
void						start_print_result(t_ft_ls_data *data, char *file);
void						print_usage(void);
void						clear_t_ft_ls_data(t_ft_ls_data *data);
void						clear_t_ft_ls_files(t_ft_ls_file *files);

DIR							*ft_open_dir(char *path);

#endif
