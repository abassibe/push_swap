/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 04:12:16 by abassibe          #+#    #+#             */
/*   Updated: 2017/10/03 05:27:12 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

static t_swap	*init_struct(int ac)
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

static void		check_double(t_swap *e)
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

static void		check_sort(t_swap *e)
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

int				main(int ac, char **av)
{
	t_swap	*e;
	char	*str;
	int		i;

	if (ac < 2)
		ft_error("error");
	e = init_struct(ac - 1);
	e->nb_max = ac - 1;
	check_numbers(ac, av);
	i = -1;
	while (++i < ac - 1)
	{
		e->tab[i] = ft_atoi(av[i + 1]);
		e->nba++;
	}
	check_double(e);
	while (get_next_line(0, &str))
		do_op(e, str);
	check_sort(e);
	return (1);
}
