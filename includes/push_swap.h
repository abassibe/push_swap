/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 04:12:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/01 01:18:42 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "../ressources/mlx.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct		s_swap
{
	int				*tab;
	int				*buff;
	int				nba;
	int				nbb;
	int				nb_max;
	int				hig;
	int				low_b;
	int				count;
	int				sa;
	int				sb;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
	void			*mlx;
	void			*win;
	void			*vimg;
	char			*img;
	int				bpp;
	int				sl;
	int				end;
}					t_swap;

void				swap_a(t_swap *e);
void				swap_b(t_swap *e);
void				swap_ab(t_swap *e);
void				push_a(t_swap *e);
void				push_b(t_swap *e);
void				rotate_a(t_swap *e);
void				rotate_b(t_swap *e);
void				rotate_ab(t_swap *e);
void				rev_rot_a(t_swap *e);
void				rev_rot_b(t_swap *e);
void				rev_rot_ab(t_swap *e);
int					check_sort(t_swap *e);
void				algo(t_swap *e);
void				visu(t_swap *e);
int					ft_error(const char *str);

void				aff_tab(t_swap *e);

#endif
