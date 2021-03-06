/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_slash.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:52:35 by blukasho          #+#    #+#             */
/*   Updated: 2019/04/10 17:53:18 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			check_slash(char *path)
{
	while (*path)
		++path;
	return (*(path - 1) == '/' ? 1 : 0);
}
