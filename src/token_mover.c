/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_mover.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 14:16:28 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/03/28 14:16:29 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		find_the_next_star(t_f *f)
{
	while (++f->j < f->t_w)
		if (f->token[f->m][f->j] == '*')
			return (1);
	while (++f->m < f->t_h)
	{
		f->j = -1;
		while (++f->j < f->t_w)
			if (f->token[f->m][f->j] == '*')
				return (1);
	}
	return (0);
}

int		find_the_first_star(t_f *f)
{
	f->m = -1;
	while (++f->m < f->t_h)
	{
		f->j = -1;
		while (++f->j < f->t_w)
			if (f->token[f->m][f->j] == '*')
				return (1);
	}
	return (0);
}
