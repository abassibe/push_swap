/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 04:12:59 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/04 02:27:25 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "stdio.h"

typedef struct		s_swap
{
	int				*tab;
	int				*buff;
	int				nba;
	int				nbb;
	int				nb_max;
}					t_swap;

void				do_op(t_swap *e, const char *str);
void				do_op_next(t_swap *e, const char *str);
void				do_op(t_swap *e, const char *str);
int					ft_error(const char *str);
t_swap				*init_struct(int ac);
void				check_sort(t_swap *e);
void				swap_ab(t_swap *e);
void				rotate_ab(t_swap *e);
void				rev_rot_ab(t_swap *e);

#endif
