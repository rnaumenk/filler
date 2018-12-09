/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:01:55 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/03/23 16:01:57 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"

int		put_the_figure(t_f *f)
{
	if (!create_the_figure(f))
		return (0);
	f->y = 0;
	f->x = 0;
	find_the_place(f);
	free_token(f);
	return (1);
}

int		play(t_f *f)
{
	if (!mapcpy(f))
		return (0);
	update_the_tax(f);
	learn_the_figure_size(f);
	if (!put_the_figure(f))
		return (0);
	return (play(f));
}

int		main(void)
{
	t_f		f;

	if (initial_values(&f))
		play(&f);
	free_map(&f);
	free_tax(&f);
	return (0);
}
