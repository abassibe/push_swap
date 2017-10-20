/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 04:12:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/10/18 05:02:03 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stdio.h"
#include <fcntl.h>

typedef struct		s_swap
{
	int				*tab;
	int				*buff;
	int				nba;
	int				nbb;
	int				nb_max;
	int				hig_a;
	int				low_b;
	int				count;
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
int					ft_error(const char *str);

void				aff_tab(t_swap *e);

#endif
