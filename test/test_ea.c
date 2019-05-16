/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ea.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:25:59 by blukasho          #+#    #+#             */
/*   Updated: 2019/05/16 17:43:17 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include <sys/xattr.h>

int			main(void)
{
	char	*value;
	char	*file;
	char	buf[100];
	int		i;
	int		c;
	int		flag;

	file = "c";
	flag = XATTR_NOFOLLOW;
	value = "blablabla";
	if (setxattr(file, "blukasho.test.ea.", value, strlen(value), 0, flag) == -1)
		ft_printf("ERROR\n");
	else
		ft_printf("SUCCESS set exattr |%s|\n", value);
	if (setxattr(file, "blukasho.test.ea.v2", value, strlen(value), 0, flag) == -1)
		ft_printf("ERROR\n");
	else
		ft_printf("SUCCESS set exattr |%s|\n", value);
	i = listxattr(file, buf, 50, XATTR_NOFOLLOW);
	ft_printf("return value listxattr() |%d|\n", i);
	c = 0;
	if (i != -1)
	{
		while (c < i)
			ft_printf("%c", buf[c++]);
		ft_printf("\n");
	}
	return (0);
}
