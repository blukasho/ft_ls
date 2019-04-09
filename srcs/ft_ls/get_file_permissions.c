/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_permissions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:42:24 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/09 16:25:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	*get_xgrp_perm(mode_t perm)
{
	if (perm & S_IXGRP)
	{
		if (perm & S_ISGID)
			return ("s");
		else
			return ("x");
	}
	else
	{
		if (perm & S_ISGID)
			return ("S");
		else
			return ("-");
	}
	return ("");
}

static char	*get_xoth_perm(mode_t perm)
{
	if (perm & S_IXOTH)
	{
		if (perm & S_ISVTX)
			return ("t");
		else
			return ("x");
	}
	else
	{
		if (perm & S_ISVTX)
			return ("T");
		else
			return ("-");
	}
	return ("");
}

static char	*get_xusr_perm(mode_t perm)
{
	if (perm & S_IXUSR)
	{
		if (perm & S_ISUID)
			return ("s");
		else
			return ("x");
	}
	else
	{
		if (perm & S_ISUID)
			return ("S");
		else
			return ("-");
	}
	return ("");
}

char		*get_file_permissions(mode_t perm)
{
	char	*p;

	p = ft_strnew(PERM_SIZE);
	(perm & S_IRUSR) ? ft_strcat(p, "r") : ft_strcat(p, "-");
	(perm & S_IWUSR) ? ft_strcat(p, "w") : ft_strcat(p, "-");
	ft_strcat(p, get_xusr_perm(perm));
	(perm & S_IRGRP) ? ft_strcat(p, "r") : ft_strcat(p, "-");
	(perm & S_IWGRP) ? ft_strcat(p, "w") : ft_strcat(p, "-");
	ft_strcat(p, get_xgrp_perm(perm));
	(perm & S_IROTH) ? ft_strcat(p, "r") : ft_strcat(p, "-");
	(perm & S_IWOTH) ? ft_strcat(p, "w") : ft_strcat(p, "-");
	ft_strcat(p, get_xoth_perm(perm));
	return (p);
}
