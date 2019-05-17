/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_acl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:01:10 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/17 13:09:11 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		check_acl(char *f)
{
	if (acl_get_file(f, ACL_TYPE_EXTENDED) || acl_get_file(f, ACL_TYPE_DEFAULT))
		return (1);
	return (0);
}
