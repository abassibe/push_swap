/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:35:14 by abassibe          #+#    #+#             */
/*   Updated: 2017/10/20 05:23:27 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void		rotate_a(t_swap *e)
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
}

static void		rotate_b(t_swap *e)
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

static void		rev_rot_a(t_swap *e)
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
}

static void		rev_rot_b(t_swap *e)
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

void			do_op_next(t_swap *e, const char *str)
{
	if (!(ft_strncmp("ra\0", str, 3)))
		rotate_a(e);
	if (!(ft_strncmp("rb\0", str, 3)))
		rotate_b(e);
	if (!(ft_strncmp("rr\0", str, 3)))
		rotate_ab(e);
	if (!(ft_strncmp("rra\0", str, 4)))
		rev_rot_a(e);
	if (!(ft_strncmp("rrb\0", str, 4)))
		rev_rot_b(e);
	if (!(ft_strncmp("rrr\0", str, 4)))
		rev_rot_ab(e);
}
