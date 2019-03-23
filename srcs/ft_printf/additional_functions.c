/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:10:16 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/11 13:35:53 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static long double	round_precision_zero(long double d)
{
	__int128 		l;
	int				r;

	l = d;
	r = l % 10;
	l = r % 2;
	if (l)
		d += 0.5;
	return (d);
}

long double		round_double(long double d)
{
	int				l;
	long double		ld;

	l = 0;
	ld = 0.5;
	if (g_data.precision > 0 && !check_exeption_double(d))
	{
		while (l++ < g_data.precision)
			ld /= 10;
		if (d > 0)
			d += ld;
		else if (d < 0)
			d -= ld;
	}
	else if (g_data.precision == 0)
		d = round_precision_zero(d);
	else if (d < 0)
		d -= 0.0000005;
	else if (d > 0)
		d += 0.0000005;
	return (d);
}

void			ft_printf_put_char(char c)
{
	write(1, &c, 1);
	++g_print_symbols;
}

void			ft_printf_put_str(char *s)
{
	while (*s)
		ft_printf_put_char(*(s++));
}

void			print_hesh(void)
{
	if (g_data.specifier == 'o')
		ft_printf_put_char('0');
	else if (g_data.specifier == 'x' || g_data.specifier == 'p')
		ft_printf_put_str("0x");
	else if (g_data.specifier == 'X')
		ft_printf_put_str("0X");
}
