/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 05:43:30 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/04 02:35:18 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		check_numbers(const int ac, char **av)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (++i < ac)
	{
		if (ft_atoi_long(av[i]) > 2147483647
				|| ft_atoi_long(av[i]) < -2147483648)
			ft_error("error");
		while (av[i][++j])
		{
			if ((av[i][j] == '+' || av[i][j] == '-') && (av[i][j + 1] != '+'
						&& av[i][j + 1] != '-'))
				j++;
			if (av[i][j] < '0' || av[i][j] > '9')
				ft_error("error");
		}
		j = -1;
	}
}

static void		check_double(const t_swap *e)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < e->nb_max)
	{
		while (j < e->nb_max)
		{
			if (e->tab[i] == e->tab[j])
				ft_error("error");
			j++;
		}
		i++;
		j = i + 1;
	}
}

static void		initiate(t_swap **e, const int ac, char **av)
{
	int		i;

	i = -1;
	*e = init_struct(ac, 1);
	(*e)->nb_max = ac - 2;
	check_numbers(ac - 1, ++av);
	while (++i < ac - 2)
	{
		(*e)->tab[i] = ft_atoi(av[i + 1]);
		(*e)->nba++;
	}
	(*e)->visu = 1;
}

static void		initiate2(t_swap **e, const int ac, char **av)
{
	int		i;

	i = -1;
	*e = init_struct(ac, 0);
	(*e)->nb_max = ac - 1;
	check_numbers(ac, av);
	while (++i < ac - 1)
	{
		(*e)->tab[i] = ft_atoi(av[i + 1]);
		(*e)->nba++;
	}
}

int				main(int ac, char **av)
{
	t_swap	*e;

	if (ac < 2)
		return (0);
	if (av[1][0] == '-' && av[1][1] == 'v')
	{
		if (ac > 3)
			initiate(&e, ac, av);
		else
			check_str_numbers(&e, av[2], 1);
	}
	else
	{
		if (ac > 2)
			initiate2(&e, ac, av);
		else
			check_str_numbers(&e, av[1], 0);
	}
	check_double(e);
	if (e->nb_max > 5)
		algo(e);
	else
		algo_inf_five(e);
	return (1);
}
