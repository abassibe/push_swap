/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 00:55:09 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/04 02:40:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_swap *e)
{
	int		tmp;

	if (e->nba < 2)
		return ;
	tmp = e->tab[0];
	e->tab[0] = e->tab[1];
	e->tab[1] = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_swap *e)
{
	int		tmp;

	if (e->nbb < 2)
		return ;
	tmp = e->buff[0];
	e->buff[0] = e->buff[1];
	e->buff[1] = tmp;
	write(1, "sb\n", 3);
}

void	swap_ab(t_swap *e)
{
	int		tmp;

	tmp = e->tab[0];
	e->tab[0] = e->tab[1];
	e->tab[1] = tmp;
	tmp = e->buff[0];
	e->buff[0] = e->buff[1];
	e->buff[1] = tmp;
	write(1, "ss\n", 3);
}

void	push_a(t_swap *e)
{
	int		i;

	i = e->nba;
	if (e->nbb < 1)
		return ;
	while (i > 0)
	{
		e->tab[i] = e->tab[i - 1];
		i--;
	}
	e->tab[0] = e->buff[0];
	while (i < e->nbb)
	{
		e->buff[i] = e->buff[i + 1];
		i++;
	}
	e->nba++;
	e->nbb--;
	e->buff[e->nbb] = 0;
	write(1, "pa\n", 3);
	if (e->visu)
		visu(e);
}

void	push_b(t_swap *e)
{
	int		i;

	i = e->nbb;
	if (e->nba < 1)
		return ;
	while (i > 0)
	{
		e->buff[i] = e->buff[i - 1];
		i--;
	}
	e->buff[0] = e->tab[0];
	while (i < e->nba)
	{
		e->tab[i] = e->tab[i + 1];
		i++;
	}
	e->nba--;
	e->nbb++;
	e->tab[e->nba] = 0;
	write(1, "pb\n", 3);
	if (e->visu)
		visu(e);
}
