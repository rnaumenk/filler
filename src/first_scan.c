/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:14:10 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/03/28 14:14:11 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

static int		create_the_taxicab(t_f *f)
{
	if (!(f->tax = (unsigned char**)malloc(sizeof(unsigned char*) *
		(f->m_h + 1))))
		return (0);
	f->tax[f->m_h] = 0;
	f->i = -1;
	while (++f->i < f->m_h)
	{
		if (!(f->tax[f->i] = (unsigned char*)ft_memalloc(sizeof(unsigned char) *
			(f->m_w + 1))))
			return (0);
	}
	return (1);
}

static int		create_the_map(t_f *f)
{
	if (!(f->map = (char**)malloc(sizeof(char*) * (f->m_h + 1))))
		return (0);
	f->map[f->m_h] = 0;
	f->i = -1;
	while (++f->i < f->m_h)
	{
		if (!(f->map[f->i] = (char*)ft_memalloc(sizeof(char) * (f->m_w + 1))))
			return (0);
	}
	return (create_the_taxicab(f));
}

static void		learn_the_number(t_f *f)
{
	get_next_line(0, &f->line);
	f->o = (f->line[10] == '1' ? 'O' : 'X');
	f->a = (f->o == 'O' ? 'X' : 'O');
	ft_strdel(&f->line);
}

int				initial_values(t_f *f)
{
	learn_the_number(f);
	get_next_line(0, &f->line);
	f->i = -1;
	while (f->line[++f->i])
	{
		if (f->line[f->i] >= 48 && f->line[f->i] <= 57)
		{
			f->m_h = ft_atoi(f->line + f->i);
			break ;
		}
	}
	while (f->line[++f->i])
	{
		if (f->line[f->i] == 32)
		{
			f->m_w = ft_atoi(f->line + f->i + 1);
			ft_strdel(&f->line);
			return (create_the_map(f));
		}
	}
	return (0);
}
