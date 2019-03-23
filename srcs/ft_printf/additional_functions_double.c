/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions_double.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:33:13 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/22 18:51:23 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		srch_int_in_arr(int *a, int a_len, int srch)
{
	while (--a_len >= 0)
		if (a[a_len] != srch)
			return (1);
	return (0);
}

void	move_int_arr(int *a, int a_len)
{
	while (a[--a_len] == 0)
		;
	while (a_len >= 0)
	{
		a[a_len + 1] = a[a_len];
		a[a_len] = 0;
		--a_len;
	}
}

