/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_acl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:47:26 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/17 17:40:06 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <sys/types.h>
#include <sys/acl.h>
#include <stdio.h>

int			main(void)
{
	char	*file;
	acl_t	acl;

	file = "c";
	acl = acl_get_file(file, ACL_TYPE_EXTENDED);
	if (acl)
		printf("OK\n");
	else
		printf("ERROR\n");
	return (0);
}
