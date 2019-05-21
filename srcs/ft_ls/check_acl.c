/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_acl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 13:01:10 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/21 18:31:06 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			check_acl(char *f)
{
	acl_t	acl;

	if ((acl = acl_get_file(f, ACL_TYPE_EXTENDED)))
	{
		acl_free(acl);
		return (1);
	}
	if ((acl = acl_get_file(f, ACL_TYPE_DEFAULT)))
	{
		acl_free(acl);
		return (1);
	}
	return (0);
}
