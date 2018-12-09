/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_searcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:29:27 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/03/28 14:29:28 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static int		try_to_put(t_f *f)
{
	f->k = -1;
	while (++f->k < f->t_h)
	{
		f->l = -1;
		while (++f->l < f->t_w)
		{
			if (!(f->k == f->m && f->l == f->j) && f->token[f->k][f->l] == '*'
				&& ((f->n + f->k - f->m) < 0 || (f->n + f->k - f->m) >= f->m_h
				|| (f->i + f->l - f->j) < 0 || (f->i + f->l - f->j) >= f->m_w ||
				f->map[f->n + (f->k - f->m)][f->i + (f->l - f->j)] != '.'))
			{
				if (!find_the_next_star(f))
					return (0);
				if (!try_to_put(f))
					return (0);
			}
		}
	}
	return (1);
}

static void		check(t_f *f, int *new_dis)
{
	if (!(f->k == f->m && f->l == f->j) && f->token[f->k][f->l] == '*' &&
		((f->n + f->k - f->m) < 0 || (f->n + f->k - f->m) >= f->m_h ||
		(f->i + f->l - f->j) < 0 || (f->i + f->l - f->j) >= f->m_w ||
		f->map[f->n + (f->k - f->m)][f->i + (f->l - f->j)] != '.'))
		*new_dis = 100001;
	else if (!(f->k == f->m && f->l == f->j) && f->token[f->k][f->l] == '*')
		*new_dis += f->tax[f->n + (f->k - f->m)][f->i + (f->l - f->j)];
}

static int		calculate_the_distance(t_f *f)
{
	int		dis;
	int		new_dis;

	dis = 100000;
	f->stop = 0;
	while (!f->stop)
	{
		new_dis = 0;
		f->k = -1;
		while (++f->k < f->t_h)
		{
			f->l = -1;
			while (++f->l < f->t_w)
				check(f, &new_dis);
		}
		if (dis > new_dis)
		{
			dis = new_dis;
			f->y1 = f->n - f->m;
			f->x1 = f->i - f->j;
		}
		if (!find_the_next_star(f))
			f->stop = 1;
	}
	return (dis);
}

void			find_the_place(t_f *f)
{
	f->dis = 100000;
	f->n = -1;
	while (++f->n < f->m_h)
	{
		f->i = -1;
		while (++f->i < f->m_w)
		{
			if ((f->map[f->n][f->i] == f->o || f->map[f->n][f->i] == f->o + 32)
				&& find_the_first_star(f) && try_to_put(f))
			{
				if (f->dis > (f->new_dis = calculate_the_distance(f)))
				{
					f->dis = f->new_dis;
					f->y = f->y1;
					f->x = f->x1;
				}
			}
		}
	}
	ft_printf("%d %d\n", f->y, f->x);
}
