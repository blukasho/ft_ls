/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:54:39 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/11 13:35:53 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				check_errors(void)
{
	if (g_data.width > 2147483646)
		return (-1);
	if (g_data.precision > 2147483641)
		return (-1);
	return (0);
}

int				check_exeption_double(long double d)
{
	__int128	a;

	a = d;
	d = d - a;
	d *= 10;
	return ((g_data.precision == 0 && !a && d == 5 ? 1 : 0));
}
