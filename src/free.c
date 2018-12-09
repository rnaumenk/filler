/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:12:12 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/03/28 14:12:13 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

void	free_tax(t_f *f)
{
	f->i = -1;
	while (++f->i < f->m_h)
	{
		free(f->tax[f->i]);
		f->tax[f->i] = NULL;
	}
	free(f->tax);
}

void	free_map(t_f *f)
{
	f->i = -1;
	while (++f->i < f->m_h)
		ft_strdel(&f->map[f->i]);
	free(f->map);
}

void	free_token(t_f *f)
{
	f->i = -1;
	while (++f->i < f->t_h)
		ft_strdel(&f->token[f->i]);
	free(f->token);
}
