/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_inf_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 02:43:20 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/04 05:44:15 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo2(t_swap *e)
{
	int		i;
	int		pivot;
	int		nb;
	int		nb2;

	pivot = get_pivot(e, e->tab, e->nbb);
	i = -1;
	nb2 = 0;
	nb = e->nbb;
	while (++i < nb - 1)
	{
		if (e->tab[0] < pivot)
		{
			push_b(e);
			nb2++;
		}
		else
			rotate_a(e);
	}
	while (nb2++ < nb - 1)
	{
		rev_rot_a(e);
		push_b(e);
	}
}

void	algo3(t_swap *e)
{
	int		i;
	int		pivot;
	int		nb;
	int		nb2;

	i = -1;
	nb = e->nbb;
	nb2 = 0;
	pivot = get_pivot(e, e->tab, e->nbb);
	while (++i < nb - 1)
	{
		if (e->tab[0] < pivot)
		{
			push_b(e);
			nb2++;
		}
		else
			rotate_a(e);
	}
	while (nb2++ < nb - 1)
	{
		rev_rot_a(e);
		push_b(e);
	}
}

void	algo4_next(t_swap *e, int count)
{
	int		i;
	int		pivot;
	int		nb;

	i = -1;
	nb = 0;
	pivot = get_pivot(e, e->buff, count);
	while (++i < count)
	{
		if (e->buff[0] > pivot)
		{
			push_a(e);
			nb++;
		}
		else
			rotate_b(e);
	}
	while (i-- > nb)
		rev_rot_b(e);
}

void	algo4(t_swap *e)
{
	int		i;
	int		pivot;
	int		nb;
	int		count;

	pivot = get_pivot(e, e->tab, e->nba);
	i = -1;
	nb = e->nba;
	count = 0;
	while (++i < nb)
	{
		if (e->tab[0] <= pivot)
		{
			push_b(e);
			count++;
		}
		else
			rotate_a(e);
	}
	algo4_next(e, count);
}

void	algo5(t_swap *e)
{
	int		pivot;
	int		i;
	int		nb;

	while (e->nba > 1)
	{
		pivot = get_pivot(e, e->tab, e->nba);
		i = -1;
		nb = e->nba;
		while (++i < nb)
		{
			if (e->tab[0] <= pivot)
				push_b(e);
			else
				rotate_a(e);
		}
	}
}
