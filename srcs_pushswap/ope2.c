/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:35:14 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/04 02:41:11 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_swap *e)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = e->tab[0];
	while (i < e->nba - 1)
	{
		e->tab[i] = e->tab[i + 1];
		i++;
	}
	e->tab[i] = tmp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_swap *e)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = e->buff[0];
	while (i < e->nbb - 1)
	{
		e->buff[i] = e->buff[i + 1];
		i++;
	}
	e->buff[i] = tmp;
	write(1, "rb\n", 3);
}

void	rotate_ab(t_swap *e)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = e->tab[0];
	while (i < e->nba - 1)
	{
		e->tab[i] = e->tab[i + 1];
		i++;
	}
	e->tab[i] = tmp;
	i = 0;
	tmp = e->buff[0];
	while (i < e->nbb - 1)
	{
		e->buff[i] = e->buff[i + 1];
		i++;
	}
	e->buff[i] = tmp;
	write(1, "rr\n", 3);
}

void	rev_rot_a(t_swap *e)
{
	int		tmp;
	int		i;

	if (e->nba < 2)
		return ;
	i = e->nba - 1;
	tmp = e->tab[i];
	while (i > 0)
	{
		e->tab[i] = e->tab[i - 1];
		i--;
	}
	e->tab[0] = tmp;
	write(1, "rra\n", 4);
}

void	rev_rot_b(t_swap *e)
{
	int		tmp;
	int		i;

	if (e->nbb < 2)
		return ;
	i = e->nbb - 1;
	tmp = e->buff[i];
	while (i > 0)
	{
		e->buff[i] = e->buff[i - 1];
		i--;
	}
	e->buff[0] = tmp;
	write(1, "rrb\n", 4);
}
