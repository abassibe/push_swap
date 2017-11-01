/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 03:22:40 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/01 05:48:55 by abassibe         ###   ########.fr       */
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
/*
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

int		first_parce(t_swap *e, int byte)
{
	int		i;

	i = -1;
	while (++i < e->nb_max)
	{
		if (!byte_value(e->tab[0], byte))
			push_b(e);
		else
			rotate_a(e);
	}
	return (e->nba);
}

int		a_is_sorted(t_swap *e)
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

int		get_higther(t_swap *e)
{
	int		i;
	int		hightest;
	int		ret;

	i = -1;
	ret = 0;
	hightest = -2147483648;
	while (++i < e->nba)
		if (e->tab[i] > hightest)
		{
			hightest = e->tab[i];
			ret = i;
		}
	e->hig = hightest;
	return (ret);
}


void	sort_a(t_swap *e, int nb_elem)
{
	int		tmp;
	int		ind;

	tmp = nb_elem;
	while (nb_elem > 0)
	{
		if (a_is_sorted(e))
			break ;
		if (tmp <= 1)
		{
			ind = get_higther(e);
			if (ind > e->nba / 2)
				while (e->tab[e->nba - 1] != e->hig)
					rev_rot_a(e);
			else
				while (e->tab[e->nba - 1] != e->hig)
					rotate_a(e);
			if (a_is_sorted(e))
				break ;
			nb_elem--;
			tmp = nb_elem;
		}
		if (e->tab[0] > e->tab[1])
			swap_a(e);
		if (a_is_sorted(e))
			break ;
		rotate_a(e);
		tmp--;
	}
}

void	algo(t_swap *e)
{
	int		i;
	int		byte;
	int		nbb;
	int		pushed;

	byte = max_byte(e->tab, e->nb_max);
	sort_a(e, first_parce(e, byte));
	byte--;
	pushed = 0;
	while (!check_sort(e))
	{
		i = -1;
		nbb = e->nbb;
		while (++i < nbb)
		{
			if (byte_value(e->buff[0], byte))
			{
				push_a(e);
				pushed++;
			}
			else
				rotate_b(e);
		}
		sort_a(e, pushed);
		pushed = 0;
		byte--;
	}
	while (e->nba != e->nb_max)
		push_a(e);
}*/

int		get_pivot(int *tab, int nb)
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

int		get_target(t_swap *e)
{
	int		i;
	int		closer;
	int		ret;

	i = -1;
	closer = 2147483647;
	while (++i < e->nbb)
		if (ft_abs(e->tab[0] - e->buff[i]) < closer)
		{
			closer = ft_abs(e->tab[0] - e->buff[i]);
			ret = e->buff[i];
		}
	return (ret);
}

int		get_up_down(t_swap *e, int target)
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

void	refill_tab(t_swap *e)
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

int		pre_sort_b(t_swap *e)
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
void	algo2(t_swap *e)
{
	int		i;
	int		pivot;
	int		nb;
	int		nb2;

	pivot = get_pivot(e->tab, e->nbb);
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
	pivot = get_pivot(e->tab, e->nbb);

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
	pivot = get_pivot(e->buff, count);
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

	pivot = get_pivot(e->tab, e->nba);
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
		pivot = get_pivot(e->tab, e->nba);
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

void	algo(t_swap *e)
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
}
