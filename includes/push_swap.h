/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 04:12:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/10/05 05:27:11 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stdio.h"

typedef struct		s_swap
{
	int				*tab;
	int				*save_tab;
	int				*tmp_tab;
	int				*buff;
	int				nba;
	int				nbb;
	int				tmp_nba;
	int				tmp_nbb;
	int				nb_max;
	void			(*sort[8])();
	int				deep;
	char			str[1000];
	int				i;
	int				tmp_i;
}					t_swap;

void				swap_a(t_swap *e);
void				swap_b(t_swap *e);
void				push_a(t_swap *e);
void				push_b(t_swap *e);
void				rotate_a(t_swap *e);
void				rotate_b(t_swap *e);
void				rev_rot_a(t_swap *e);
void				rev_rot_b(t_swap *e);
int					check_sort(t_swap *e);
void				algo(t_swap *e);
void				assign_func(t_swap *e);
void				recurs(t_swap *e);

#endif
