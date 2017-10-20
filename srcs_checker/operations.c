/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 00:55:09 by abassibe          #+#    #+#             */
/*   Updated: 2017/10/20 05:19:47 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void		swap_a(t_swap *e)
{
	int		tmp;

	if (e->nba < 2)
		return ;
	tmp = e->tab[0];
	e->tab[0] = e->tab[1];
	e->tab[1] = tmp;
}

static void		swap_b(t_swap *e)
{
	int		tmp;

	if (e->nbb < 2)
		return ;
	tmp = e->buff[0];
	e->buff[0] = e->buff[1];
	e->buff[1] = tmp;
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

static void		push_a(t_swap *e)
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
	while (i < e->nbb - 1)
	{
		e->buff[i] = e->buff[i + 1];
		i++;
	}
	e->nba++;
	e->nbb--;
	e->buff[e->nbb] = 0;
}

static void		push_b(t_swap *e)
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
}

void			do_op(t_swap *e, const char *str)
{
	if (!(ft_strncmp("sa\0", str, 3)))
		swap_a(e);
	else if (!(ft_strncmp("sb\0", str, 3)))
		swap_b(e);
	else if (!(ft_strncmp("ss\0", str, 3)))
		swap_ab(e);
	else if (!(ft_strncmp("pa\0", str, 3)))
		push_a(e);
	else if (!(ft_strncmp("pb\0", str, 3)))
		push_b(e);
	else
		do_op_next(e, str);
}
