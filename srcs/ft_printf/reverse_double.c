/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:25:32 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/11 19:34:58 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				reverse_double(char *s)
{
	int				start;
	int				end;
	char			tmp;

	end = ft_strlen(s);
	start = 0;
	while (start < end && (tmp = s[start]))
	{
		s[start++] = s[--end];
		s[end] = tmp;
	}
}
