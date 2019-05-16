/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_acl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:47:26 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/16 18:26:03 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
#include <sys/types.h>
#include <sys/acl.h>

int			main(void)
{
	char	*file;
	acl_t	acl;

	file = "/Library";
	acl = acl_get_file(file, ACL_TYPE_EXTENDED);
	if (acl)
		ft_printf("OK\n");
	else
		ft_printf("ERROR\n");
	return (0);
}
