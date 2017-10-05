/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 00:55:09 by abassibe          #+#    #+#             */
/*   Updated: 2017/10/05 05:59:04 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_sort(t_swap *e)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < e->nb_max - 1)
	{
		if (e->tab[i] > e->tab[i + 1])
			return (0);
		i++;
	}
	if (e->nba == e->nb_max && e->nbb == 0)
	{
		while (j < e->i)
		{
			if (e->str[j] == '0')
				printf("sa\n");
			if (e->str[j] == '1')
				printf("sb\n");
			if (e->str[j] == '2')
				printf("pa\n");
			if (e->str[j] == '3')
				printf("pb\n");
			if (e->str[j] == '4')
				printf("ra\n");
			if (e->str[j] == '5')
				printf("rb\n");
			if (e->str[j] == '6')
				printf("rra\n");
			if (e->str[j] == '7')
				printf("rrb\n");
			j++;
		}
		exit(1);
	}
	return (0);
}

void	swap_a(t_swap *e)
{
	int		tmp;
	int		i;

	i = 0;
	if (e->nba < 2)
		return ;
	tmp = e->tab[0];
	e->tab[0] = e->tab[1];
	e->tab[1] = tmp;
	e->str[e->i] = '0';
	e->i++;
	printf("SA\n");
}

void	swap_b(t_swap *e)
{
	int		tmp;
	int		i;

	i = 0;
	if (e->nbb < 2)
		return ;
	tmp = e->buff[0];
	e->buff[0] = e->buff[1];
	e->buff[1] = tmp;
	e->str[e->i] = '1';
	e->i++;
	printf("SB\n");
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
	while (i < e->nb_max - 1)
	{
		e->buff[i] = e->buff[i + 1];
		i++;
	}
	e->nba++;
	e->nbb--;
	e->buff[e->nbb + 1] = 0;
	e->str[e->i] = '2';
	e->i++;
	printf("PA\n");
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
	e->nba--;
	while (i < e->nba)
	{
		e->tab[i] = e->tab[i + 1];
		i++;
	}
	e->nbb++;
	e->tab[e->nba] = 0;
	e->str[e->i] = '3';
	e->i++;
	printf("PB\n");
}
