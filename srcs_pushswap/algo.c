/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 03:22:40 by abassibe          #+#    #+#             */
/*   Updated: 2017/10/04 06:18:16 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_func(t_swap *e, int target)
{
	if (target == 0)
		e->sort = swap_a;
	if (target == 1)
		e->sort = swap_b;
	if (target == 2)
		e->sort = push_a;
	if (target == 3)
		e->sort = push_b;
	if (target == 4)
		e->sort = rotate_a;
	if (target == 5)
		e->sort = rotate_b;
	if (target == 6)
		e->sort = rev_rot_a;
	if (target == 7)
		e->sort = rev_rot_b;
}

void	algo(t_swap *e, int target)
{
	assign_func(e, target);
	e->sort(e);
	target++;
	if (target < 8)
		algo(e, target);
}
