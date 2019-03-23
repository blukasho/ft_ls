/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 13:28:07 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/23 17:38:56 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>

typedef struct				s_ft_ls_dir
{                           
	char					*dir;
	struct s_ft_ls_dir		*next;
}							t_ft_ls_dir;

typedef struct				s_ft_ls_data
{                           
	int						l;
	int						a;
	int						r;
	int						t;
	int						R;
	t_ft_ls_dir				*dirs;
}							t_ft_ls_data;

t_ft_ls_dir					*get_t_ft_ls_dir(t_ft_ls_dir *dirs, char *s);
                            
t_ft_ls_data				*ft_read_args(int ar, char **av);
t_ft_ls_data				*get_t_ft_ls_data(void);

int							ft_read_flags(char *flags, t_ft_ls_data *data);
int							error_invalid_flag(char f);

void						print_usage(void);
void						clear_t_ft_ls_data(t_ft_ls_data *data);
void						clear_t_ft_ls_dirs(t_ft_ls_dir *dirs);
void						ft_open_dir(char *path);

#endif
