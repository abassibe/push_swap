/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 04:12:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/07 00:38:58 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "../ressources/mlx.h"

typedef struct		s_swap
{
	int				*tab;
	int				*buff;
	int				nba;
	int				nbb;
	int				nb_max;
	int				visu;
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
int					algo(t_swap *e);
void				visu(t_swap *e);
void				algo_inf_five(t_swap *e);
void				algo2(t_swap *e);
void				algo3(t_swap *e);
void				algo4(t_swap *e);
void				algo4_next(t_swap *e, int count);
void				algo5(t_swap *e);
int					get_pivot(t_swap *e, int *tab, const int nb);
int					get_target(t_swap *e);
t_swap				*init_struct(const int ac, const int visu);
void				check_str_numbers(t_swap **e, const char *str, int visu);
int					is_sort(t_swap *e);
int					ft_error(const char *str);

#endif
