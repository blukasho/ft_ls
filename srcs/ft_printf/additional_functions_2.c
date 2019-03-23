/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:40:08 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/11 20:50:01 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		get_double_bits(__int128 li)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < 80)
	{
		if (li & 0x1)
			g_data.double_bit_mask[i] = '1';
		else
			g_data.double_bit_mask[i] = '0';
		li = li >> 1;
		++i;
	}
	g_data.double_bit_mask[i] = '\0';
}

void		get_double_exp(void)
{
	int		i;

	i = 1;
	while (i++ < 15)
	{
		g_data.double_exp = g_data.double_exp << 1;
		if (g_data.double_bit_mask[i] == '1')
			g_data.double_exp = g_data.double_exp | 0x1;
	}
}
