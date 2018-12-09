/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:02:08 by rnaumenk          #+#    #+#             */
/*   Updated: 2018/03/23 16:02:09 by rnaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# include "../libft/include/libft.h"

typedef struct	s_f
{
	int				pl_nu;
	char			*line;
	char			**map;
	unsigned char	**tax;
	char			o;
	char			a;
	int				i;
	int				n;
	int				j;
	int				m;
	int				k;
	int				l;
	int				dis;
	int				new_dis;
	int				m_h;
	int				m_w;
	int				t_h;
	int				t_w;
	char			**token;
	int				zero_found;
	int				num;
	int				y;
	int				x;
	int				y1;
	int				x1;
	int				stop;
}				t_f;

void			free_tax(t_f *f);
void			free_map(t_f *f);
void			free_token(t_f *f);
int				initial_values(t_f *f);
int				find_the_next_star(t_f *f);
int				find_the_first_star(t_f *f);
void			update_the_tax(t_f *f);
int				mapcpy(t_f *f);
void			learn_the_figure_size(t_f *f);
int				create_the_figure(t_f *f);
void			find_the_place(t_f *f);

#endif
