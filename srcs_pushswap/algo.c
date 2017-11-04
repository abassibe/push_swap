/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 03:22:40 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/04 02:53:32 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				get_pivot(int *tab, const int nb)
{
	int		total;
	int		closer;
	int		i;
	int		ret;

	total = 0;
	closer = 2147483647;
	i = -1;
	ret = 0;
	while (++i < nb)
		total += tab[i];
	total /= nb;
	i = -1;
	while (++i < nb)
		if (ft_abs(total - tab[i]) < closer)
		{
			closer = ft_abs(total - tab[i]);
			ret = tab[i];
		}
	return (ret);
}

static int		get_up_down(t_swap *e, const int target)
{
	int		i;
	int		rb;
	int		rrb;

	i = 0;
	rb = 0;
	rrb = 0;
	while (e->buff[i] != target)
	{
		rb++;
		i++;
	}
	i = e->nbb - 1;
	while (e->buff[i] != target)
	{
		rrb++;
		i--;
	}
	if (rb > rrb)
		return (1);
	else
		return (0);
}

static void		refill_tab(t_swap *e)
{
	int		i;
	int		target;

	i = 0;
	target = 0;
	while (e->nba != e->nb_max)
	{
		if (e->nba > 1 && e->tab[0] > e->tab[1])
			swap_a(e);
		else
		{
			target = get_target(e);
			if (e->buff[0] == target)
				push_a(e);
			else if (!get_up_down(e, target))
				rotate_b(e);
			else if (get_up_down(e, target))
				rev_rot_b(e);
		}
	}
}

static int		pre_sort_b(t_swap *e)
{
	int		i;
	int		pivot;
	int		nb;

	i = -1;
	pivot = get_pivot(e->buff, e->nbb);
	nb = e->nbb;
	while (++i < nb)
	{
		if (e->buff[0] > pivot)
			push_a(e);
		else
			rotate_b(e);
	}
	return (i);
}

int				algo(t_swap *e)
{
	int		pivot;
	int		i;
	int		nb;

	pivot = get_pivot(e->tab, e->nb_max);
	i = -1;
	while (++i < e->nb_max)
	{
		if (e->tab[0] <= pivot)
			push_b(e);
		else
			rotate_a(e);
	}
	pre_sort_b(e);
	nb = e->nbb;
	i = pre_sort_b(e);
	while (i-- > nb)
		push_b(e);
	algo2(e);
	algo3(e);
	if (e->nb_max >= 500)
		algo4(e);
	algo5(e);
	refill_tab(e);
	return (1);
}
