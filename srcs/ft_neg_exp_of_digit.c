/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neg_exp_of_digit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blukasho <bodik1w@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:26:33 by blukasho          #+#    #+#             */
/*   Updated: 2019/03/22 18:55:50 by blukasho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_neg_exp_of_digit	*init(int dig, int base, int div)
{
	t_neg_exp_of_digit		*s;

	s = (t_neg_exp_of_digit *)malloc(sizeof(t_neg_exp_of_digit));
	ft_bzero(s, sizeof(t_neg_exp_of_digit));
	s->r_len = dig * base;
	s->r = (int *)malloc(s->r_len * sizeof(int));
	ft_bzero(s->r, s->r_len * sizeof(int));
	s->div_len = div + 1;
	s->div = (int *)malloc(s->div_len * sizeof(int));
	ft_bzero(s->div, s->div_len * sizeof(int));
	s->per_len = MAX_PERIOD;
	s->per = (int *)malloc(s->per_len * sizeof(int));
	ft_bzero(s->per, s->per_len * sizeof(int));
	s->div[0] = 1;
	s->sw = 1;
	s->r_pos = 1;
	s->tmp = 1;
	return (s);
}

static int					check_period(t_neg_exp_of_digit *neg)
{
	int						i;
	int						r;

	r = 0;
	i = neg->div_len;
	while (i >= 0 && neg->div[--i] == 0)
		;
	if (i >= 0)
	{
		while (i >= 0)
		{
			r *= 10;
			r += neg->div[i--];
		}
		i = 0;
		while (i < neg->per_len && neg->per[i] > 0)
			if (neg->per[i++] == r)
				return (1);
		neg->per[i] = r;
	}
	return (0);
}

static int					get_result_sum(int *a, int *b, int a_len, int b_len)
{
	int						r;
	t_sum_two_digits		*sum;
	t_sum_two_digits		*tmp;
	t_sum_two_digits		*tmp2;

	r = 0;
	sum = (t_sum_two_digits *)malloc(sizeof(t_sum_two_digits));
	ft_bzero(sum, sizeof(t_sum_two_digits));
	sum->r_len = 1;
	sum->r = (int *)malloc(sum->r_len * sizeof(int));
	ft_bzero(sum->r, sum->r_len * sizeof(int));
	while (ft_int_arr_comparing(a, sum->r, a_len, sum->r_len) == 1 && ++r)
	{
		tmp = sum;
		sum = ft_sum_two_digits(tmp->r, b, tmp->r_len, b_len);
		tmp2 = ft_sum_two_digits(sum->r, b, sum->r_len, b_len);
		if (ft_int_arr_comparing(a, tmp2->r, a_len, tmp2->r_len)  == -1)
		{
			ft_memdel((void **)&tmp->r);
			ft_memdel((void **)&tmp);
			ft_memdel((void **)&tmp2->r);
			ft_memdel((void **)&tmp2);
			return (r);
		}
	}
	return (0);
}

static void					get_subt_res(t_neg_exp_of_digit *n, t_pos_exp_of_digit *p)
{
	t_int_arr_subtr			*m;
	int						i;

	while (ft_int_arr_comparing(n->div, p->r, n->div_len, p->r_len) >= 0)
	{
		i = 0;
		m = ft_int_arr_subtr(n->div, p->r, n->div_len, p->r_len);
		while (i < n->div_len)
			n->div[i++] = 0;
		while (m->r[--(m->r_len)] == 0)
			;
		while (m->r_len >= 0)
		{
			n->div[m->r_len] = m->r[m->r_len];
			--(m->r_len);
		}
	}
}

t_neg_exp_of_digit			*ft_neg_exp_of_digit(int dig, int base)
{
	t_neg_exp_of_digit		*neg;
	t_pos_exp_of_digit		*pos;
	int						i;

	base = -base;
	pos = ft_pos_exp_of_digit(dig, base);
	neg = init(dig, base, pos->r_len);
	while (srch_int_in_arr(neg->div, neg->div_len, 0))
	{
		while (ft_int_arr_comparing(neg->div, pos->r, neg->div_len, pos->r_len) == -1)
		{
			if (check_period(neg))
				return (neg);
			move_int_arr(neg->div, neg->div_len);
			if (ft_int_arr_comparing(neg->div, pos->r, neg->div_len, pos->r_len) == -1)
				neg->r[neg->r_pos++] = 0;
		}
		neg->r[neg->r_pos++] = get_result_sum(neg->div, pos->r, neg->div_len, pos->r_len);
		get_subt_res(neg, pos);
	}
	return (neg);
}
