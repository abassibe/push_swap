/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 03:22:40 by abassibe          #+#    #+#             */
/*   Updated: 2017/10/20 05:08:26 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
int		get_lowest(t_swap *e)
{
	int		ret;
	int		i;
	int		tmp;

	ret = 0;
	i = 0;
	tmp = 2147483647;
	while (i < e->nba)
	{
		if (e->tab[i] < tmp)
		{
			ret = i;
			tmp = e->tab[ret];
		}
		i++;
	}
	return (ret);
}

void	algo(t_swap *e)
{
	int		i;
	int		low;

	i = 0;
	low = 0;
	while (!check_sort(e))
	{
		i = get_lowest(e);
		low = e->tab[i];
		while (e->tab[0] != low)
		{
			if (i < e->nb_max / 2)
			{
				rotate_a(e);
				i--;
			}
			else
			{
				rev_rot_a(e);
				i++;
				if (i > e->nb_max)
					i = 0;
			}
		}
		push_b(e);
		if (e->nba == 0 || e->nba == 1)
			while (e->nba < e->nb_max)
				push_a(e);
	}
}*/
/*
void	split(t_swap *e)
{
	int		pivot;
	int		i;

	pivot = e->nb_max / 2;
	i = -1;
	while (++i < e->nb_max)
	{
		if (e->tab[0] <= pivot)
			push_b(e);
		else
			rotate_a(e);
	}
}

void	put_lower_bot(t_swap *e)
{
	int		i;
	int		lowest;

	i = -1;
	lowest = 2147483647;
	while (++i < e->nbb)
	{
		if (e->buff[i] < lowest)
			lowest = e->buff[i];
	}
	e->low_b = lowest;
}

void	put_higther_bot(t_swap *e)
{
	int		i;
	int		hightest;

	i = -1;
	hightest = -2147483648;
	while (++i < e->nba)
	{
		if (e->tab[i] > hightest)
			hightest = e->tab[i];
	}
	i = -1;
	e->hig_a = hightest;
}

int		a_is_sorted(int *tab, int nb, int hightest)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < nb)
		if (tab[i] == hightest)
			j = i;
	i = -1;
	while (++i < nb - 1)
	{
		if (j > 0 && tab[j] < tab[j - 1])
			return (0);
		else if (j == 0 && tab[0] < tab[nb - 1])
			return (0);
		if (j == 0)
			j = nb;
		j--;
	}
	return (1);
}

int		b_is_sorted(int *tab, int nb, int lowest)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < nb)
		if (tab[i] == lowest)
			j = i;
	i = -1;
	while (++i < nb - 1)
	{
		if (j > 0 && tab[j] > tab[j - 1])
			return (0);
		else if (j == 0 && tab[0] > tab[nb - 1])
			return (0);
		if (j == 0)
			j = nb;
		j--;
	}
	return (1);
}

void	replace(t_swap *e)
{
	while (e->tab[e->nba - 1] != e->hig_a)
		rotate_ab(e);
	while (e->nba != e->nb_max)
	{
		if (e->buff[0] == e->tab[0] - 1)
			push_a(e);
		else
		{
			if (e->buff[0] > e->nbb / 2)
				rev_rot_b(e);
			else
				rotate_b(e);
		}
	}
}

void	algo(t_swap *e)
{
	split(e);
	put_lower_bot(e);
	put_higther_bot(e);
	while (!(a_is_sorted(e->tab, e->nba, e->hig_a)) || !(b_is_sorted(e->buff, e->nbb, e->low_b)))
	{
		if ((e->tab[0] < e->tab[1] || e->tab[0] == e->hig_a) && (e->buff[0] > e->buff[1] || e->buff[0] == e->low_b))
			rotate_ab(e);
		else if ((e->tab[0] != e->hig_a && e->tab[0] > e->tab[1]) && (e->buff[0] != e->low_b && e->buff[0] < e->buff[1]))
			swap_ab(e);
		else if (e->tab[0] != e->hig_a && e->tab[0] > e->tab[1] && e->tab[0])
			swap_a(e);
		else if (e->buff[0] != e->low_b && e->buff[0] < e->buff[1])
			swap_b(e);
	}
	replace(e);
	if (!check_sort(e->tab, e->nb_max))
	{
		aff_tab(e);
		ft_error("error");
	}
}
*/

int		byte_value(int nb, int i)
{
	return ((nb >> i) & 1);
}

int		max_byte(int *tab, int nb)
{
	int		i;
	int		j;
	int		ret;

	i = 32;
	j = -1;
	ret = 0;
	while (++j < nb)
	{
		while (--i > 0)
		{
			if (ret > i)
				break ;
			if (byte_value(tab[j], i) && i > ret)
				ret = i;
		}
		i = 32;
	}
	return (ret);
}

void	algo(t_swap *e)
{
	int		i;
	int		j;
	int		nba;
	int		nbb;
	int		byte;

	j = -1;
	byte = max_byte(e->tab, e->nb_max);
	while (++j < byte + 1)
	{
		nba = e->nba;
		i = -1;
		while (++i < nba)
		{
			if (!byte_value(e->tab[0], j))
				push_b(e);
			else
				rotate_a(e);
		}
		i = -1;
		nbb = e->nbb;
		while (j > 0 && ++i < nbb)
		{
			if (byte_value(e->buff[0], j))
				push_a(e);
			else
				rotate_b(e);
		}
	}
	while (e->nba != e->nb_max)
		push_a(e);
}
