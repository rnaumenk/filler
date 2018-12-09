/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_figure_scan.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:22:14 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/03/28 14:22:15 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		mapcpy(t_f *f)
{
	if (!(get_next_line(0, &f->line)))
		return (0);
	while (f->line[4] != '0')
	{
		ft_strdel(&f->line);
		get_next_line(0, &f->line);
	}
	ft_strdel(&f->line);
	f->i = -1;
	while (++f->i < f->m_h)
	{
		get_next_line(0, &f->line);
		ft_memcpy(f->map[f->i], f->line + 4, f->m_w);
		ft_strdel(&f->line);
	}
	return (1);
}

void	learn_the_figure_size(t_f *f)
{
	get_next_line(0, &f->line);
	f->i = -1;
	while (f->line[++f->i])
	{
		if (f->line[f->i] >= 48 && f->line[f->i] <= 57)
		{
			f->t_h = ft_atoi(f->line + f->i);
			break ;
		}
	}
	while (f->line[++f->i])
	{
		if (f->line[f->i] == 32)
		{
			f->t_w = ft_atoi(f->line + f->i + 1);
			ft_strdel(&f->line);
			break ;
		}
	}
}

int		create_the_figure(t_f *f)
{
	if (!(f->token = (char**)malloc(sizeof(char*) * (f->t_h + 1))))
		return (0);
	f->token[f->t_h] = 0;
	f->i = -1;
	while (++f->i < f->t_h)
	{
		if (!(f->token[f->i] = (char*)ft_memalloc(sizeof(char) * (f->t_w + 1))))
			return (0);
		get_next_line(0, &f->line);
		ft_memcpy(f->token[f->i], f->line, f->t_w);
		ft_strdel(&f->line);
	}
	return (1);
}
