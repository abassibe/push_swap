/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_the_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 02:26:18 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/04 02:28:16 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_swap	*init_struct(int ac)
{
	t_swap	*e;

	if (!(e = (t_swap *)ft_memalloc(sizeof(t_swap))))
		ft_error("error malloc");
	if (!(e->tab = (int *)ft_memalloc(sizeof(int) * ac)))
		ft_error("error malloc");
	if (!(e->buff = (int *)ft_memalloc(sizeof(int) * ac)))
		ft_error("error malloc");
	return (e);
}

void	check_sort(t_swap *e)
{
	int		i;

	i = 0;
	while (i < e->nb_max - 1)
	{
		if (e->tab[i] > e->tab[i + 1])
			ft_error("KO");
		i++;
	}
	if (e->nba == e->nb_max && e->nbb == 0)
		ft_printf("OK\n");
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
}

void	rev_rot_ab(t_swap *e)
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
}
