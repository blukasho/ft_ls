/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:30:57 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/11 19:23:34 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			print_3(int m)
{
	while (g_data.width-- > 0)
		ft_printf_put_char(' ');
	if (g_data.flags[3] == '+' || m)
	{
		if (m)
			ft_printf_put_char('-');
		else
			ft_printf_put_char('+');
	}
}

static void			print_2(char *s, int m, long double d)
{
	if (!print_inf(s, d, m) && !print_nan(s, d))
	{
		if (g_data.flags[1] == '0')
		{
			if (g_data.flags[3] == '+' || m)
			{
				if (m)
					ft_printf_put_char('-');
				else
					ft_printf_put_char('+');
			}
			while (g_data.width-- > 0)
				ft_printf_put_char('0');
		}
		else
			print_3(m);
		ft_printf_put_str(s);
		if (g_data.flags[0] == '#' && g_data.precision == 0)
			ft_printf_put_char('.');
	}
}

static void			print_1(char *s, int m, long double d)
{
	if (!print_inf(s, d, m) && !print_nan(s, d))
	{
		if (g_data.flags[3] == '+' || m)
		{
			if (m)
				ft_printf_put_char('-');
			else
				ft_printf_put_char('+');
		}
		ft_printf_put_str(s);
		if (g_data.flags[0] == '#' && g_data.precision == 0)
			ft_printf_put_char('.');
		while (g_data.width-- > 0)
			ft_printf_put_char(' ');
	}
}

static void			print(long double d)
{
	char			s[80000];
	int				m;

	double_to_string(d);
/*
	if ((d == -0 || d < 0) && (m = 1))
		d = -d;
	else
		m = 0;

	if (g_data.precision == -1)
		g_data.precision = 6;
	if (g_data.flags[0] == '#' && g_data.precision == 0 && d == d)
		--g_data.width;
	if ((g_data.flags[3] == '+' || m) && d == d)
		--g_data.width;
	d = round_double(d);
	if (g_data.flags[2] == ' ' && g_data.flags[3] != '+' && d == d && !m)
	{
		--g_data.width;
		ft_printf_put_char(' ');
	}
	if (g_data.flags[4] == '-')
		print_1(s, m, d);
	else
		print_2(s, m, d);
		*/
}

void				print_double(va_list ap)
{
	if (g_data.length == 3)
		print(va_arg(ap, long double));
	else
		print(va_arg(ap, double));
}
