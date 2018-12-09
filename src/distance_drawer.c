/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_drawer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:18:40 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/03/28 14:18:41 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static void		put_the_number(t_f *f)
{
	if ((f->i - 1) >= 0 && f->tax[f->n][f->i - 1] == 253)
	{
		f->tax[f->n][f->i - 1] = (f->num == 255 ? 1 : f->num + 1);
		f->zero_found = 1;
	}
	if ((f->i + 1) < f->m_w && f->tax[f->n][f->i + 1] == 253)
	{
		f->tax[f->n][f->i + 1] = (f->num == 255 ? 1 : f->num + 1);
		f->zero_found = 1;
	}
	if ((f->n - 1) >= 0 && f->tax[f->n - 1][f->i] == 253)
	{
		f->tax[f->n - 1][f->i] = (f->num == 255 ? 1 : f->num + 1);
		f->zero_found = 1;
	}
	if ((f->n + 1) < f->m_h && f->tax[f->n + 1][f->i] == 253)
	{
		f->tax[f->n + 1][f->i] = (f->num == 255 ? 1 : f->num + 1);
		f->zero_found = 1;
	}
}

static void		draw_around(t_f *f)
{
	f->zero_found = 1;
	while (f->zero_found == 1)
	{
		f->zero_found = 0;
		f->n = -1;
		while (++f->n < f->m_h)
		{
			f->i = -1;
			while (++f->i < f->m_w)
			{
				if (f->tax[f->n][f->i] == (unsigned char)f->num)
					put_the_number(f);
			}
		}
		f->num = (f->num == 255 ? 1 : f->num + 1);
	}
}

void			update_the_tax(t_f *f)
{
	f->i = -1;
	while (++f->i < f->m_h)
		ft_memcpy(f->tax[f->i], f->map[f->i], f->m_w);
	f->n = -1;
	while (++f->n < f->m_h)
	{
		f->i = -1;
		while (++f->i < f->m_w)
			if (f->tax[f->n][f->i] == '.')
				f->tax[f->n][f->i] = 253;
	}
	f->n = -1;
	while (++f->n < f->m_h)
	{
		f->i = -1;
		while (++f->i < f->m_w)
		{
			if (f->tax[f->n][f->i] == f->a || f->tax[f->n][f->i] == f->a + 32)
				f->tax[f->n][f->i] = 255;
			if (f->tax[f->n][f->i] == f->o || f->tax[f->n][f->i] == f->o + 32)
				f->tax[f->n][f->i] = 254;
		}
	}
	f->num = 255;
	draw_around(f);
}
