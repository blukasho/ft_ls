/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:01:12 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/11 13:35:53 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			print_pointer(va_list ap)
{
	void		*ptr;
	intptr_t	p;

	ptr = va_arg(ap, void *);
	p = (intptr_t)ptr;
	g_data.specifier = 'p';
	g_data.length = 1;
	g_data.flags[0] = '#';
	print_hex(p);
}
