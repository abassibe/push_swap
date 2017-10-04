/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 00:55:09 by abassibe          #+#    #+#             */
/*   Updated: 2017/10/04 06:18:06 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_sort(t_swap *e)
{
	int		i;

	i = 0;
	while (i < e->nb_max - 1)
	{
		if (e->tab[i] > e->tab[i + 1])
		{
			ft_memcpy(e->tab, e->save_tab, sizeof(e->save_tab));
			e->nba = e->nb_max;
			e->nbb = 0;
			return (0);
		}
		i++;
	}
	if (e->nba == e->nb_max && e->nbb == 0)
	{
		printf("GG\n");
		exit (1);
	}
	return (0);
}

void	swap_a(t_swap *e)
{
	int		tmp;

	if (e->nba < 2)
		return ;
	tmp = e->tab[0];
	e->tab[0] = e->tab[1];
	e->tab[1] = tmp;
	check_sort(e);
}

void	swap_b(t_swap *e)
{
	int		tmp;

	if (e->nbb < 2)
		return ;
	tmp = e->buff[0];
	e->buff[0] = e->buff[1];
	e->buff[1] = tmp;
	check_sort(e);
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
	e->tab[0] = e->buff[e->nbb];
	while (i < e->nb_max - 1)
	{
		e->buff[i] = e->buff[i + 1];
		i++;
	}
	e->nba++;
	e->nbb--;
	e->buff[e->nb_max - 1] = 0;
	check_sort(e);
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
	e->buff[0] = e->tab[e->nba];
	while (i < e->nb_max - 1)
	{
		e->tab[i] = e->tab[i + 1];
		i++;
	}
	e->nba--;
	e->nbb++;
	e->tab[e->nb_max - 1] = 0;
	check_sort(e);
}
