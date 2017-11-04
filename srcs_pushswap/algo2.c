/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 01:23:51 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/04 02:37:24 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_higther_bot(t_swap *e)
{
	int		tmp;
	int		i;

	tmp = -2147483648;
	i = -1;
	while (++i < e->nb_max)
		if (e->tab[i] > tmp)
			tmp = e->tab[i];
	if (e->tab[0] == tmp)
		rotate_a(e);
	if (e->tab[1] == tmp)
	{
		rotate_a(e);
		rotate_a(e);
	}
	if (e->tab[2] == tmp)
	{
		rev_rot_a(e);
		rev_rot_a(e);
	}
	if (e->tab[3] == tmp)
		rev_rot_a(e);
}

void	algo_five(t_swap *e)
{
	put_higther_bot(e);
	while (e->nba > 3)
	{
		if (e->tab[0] < e->tab[1])
			push_b(e);
		else
		{
			swap_a(e);
			push_b(e);
		}
	}
	if (e->tab[0] > e->tab[1])
		swap_a(e);
	if (e->buff[0] < e->buff[1])
		swap_b(e);
	push_a(e);
	if (e->tab[0] > e->tab[1])
		swap_a(e);
	push_a(e);
	if (e->tab[0] > e->tab[1])
		swap_a(e);
}

int		is_sort(t_swap *e)
{
	int		i;

	i = 0;
	while (i < e->nba - 1)
	{
		if (e->tab[i] > e->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	algo_four(t_swap *e)
{
	int		pivot;

	pivot = (e->tab[0] + e->tab[1] + e->tab[2] + e->tab[3]) / 4;
	while (e->nba > 2)
	{
		if (e->tab[0] <= pivot)
			push_b(e);
		else
			rotate_a(e);
	}
	if (e->tab[0] > e->tab[1] && e->buff[0] < e->buff[1])
		rotate_ab(e);
	else if (e->tab[0] > e->tab[1])
		rotate_a(e);
	else if (e->buff[0] < e->buff[1])
		rotate_b(e);
	push_a(e);
	push_a(e);
}

void	algo_inf_five(t_swap *e)
{
	if (e->nb_max == 5)
		algo_five(e);
	else if (e->nb_max == 4)
		algo_four(e);
	else if (e->nb_max == 3)
	{
		while (e->tab[2] < e->tab[0] || e->tab[2] < e->tab[1])
			rotate_a(e);
		if (e->tab[0] > e->tab[1])
			swap_a(e);
	}
	else
	{
		if (e->tab[0] > e->tab[1])
			swap_a(e);
	}
}
