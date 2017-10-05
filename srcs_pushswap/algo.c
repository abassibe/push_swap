/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 03:22:40 by abassibe          #+#    #+#             */
/*   Updated: 2017/10/05 06:15:17 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	assign_func(t_swap *e)
{
	e->sort[0] = swap_a;
	e->sort[1] = swap_b;
	e->sort[2] = push_a;
	e->sort[3] = push_b;
	e->sort[4] = rotate_a;
	e->sort[5] = rotate_b;
	e->sort[6] = rev_rot_a;
	e->sort[7] = rev_rot_b;
}

void	recurs(t_swap *e)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	algo(e);
	while (i < 8)
	{
		e->sort[i](e);
		if (check == 1)
			recurs(e);
		algo(e);
		ft_memcpy(e->tmp_tab, e->tab, e->nb_max * sizeof(int));
		e->tmp_nba = e->nba;
		e->tmp_nbb = e->nbb;
		e->tmp_i = e->i;
		i++;
		if (i == 8)
		{
			i = 0;
			check = 1;
		}
	}
}

void	algo(t_swap *e)
{
	int		i;

	i = 0;
	while (i < 8)
	{
//		sleep(1);
		printf("AVANT %d a = [%d][%d][%d][%d], b = [%d][%d][%d][%d], cpy = [%d][%d][%d][%d]\n", i, e->tab[0], e->tab[1], e->tab[2], e->tab[3], e->buff[0], e->buff[1], e->buff[2], e->buff[3], e->tmp_tab[0], e->tmp_tab[1], e->tmp_tab[2], e->tmp_tab[3]);
		e->sort[i](e);
		printf("APRES %d a = [%d][%d][%d][%d], b = [%d][%d][%d][%d], cpy = [%d][%d][%d][%d]\n", i, e->tab[0], e->tab[1], e->tab[2], e->tab[3], e->buff[0], e->buff[1], e->buff[2], e->buff[3], e->tmp_tab[0], e->tmp_tab[1], e->tmp_tab[2], e->tmp_tab[3]);
		check_sort(e);
		ft_memcpy(e->tab, e->tmp_tab, e->nb_max * sizeof(int));
		ft_memset(e->buff, 0, e->nb_max * sizeof(int));
		e->str[e->i] = 0;
		e->i = e->tmp_i;
		e->nba = e->tmp_nba;
		e->nbb = e->tmp_nbb;
		i++;
	}
}
