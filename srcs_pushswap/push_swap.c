/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 05:43:30 by abassibe          #+#    #+#             */
/*   Updated: 2017/10/26 04:13:30 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				ft_error(const char *str)
{
	ft_fprintf(2, "%s\n", str);
	exit(0);
}

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

static t_swap	*init_struct(int ac)
{
	t_swap	*e;
	int		i;

		i = 0;
	if (!(e = (t_swap *)ft_memalloc(sizeof(t_swap))))
		ft_error("error malloc");
	if (!(e->tab = (int *)ft_memalloc(sizeof(int) * ac)))
		ft_error("error malloc");
	if (!(e->buff = (int *)ft_memalloc(sizeof(int) * ac)))
		ft_error("error malloc");
	return (e);
}

void			aff_tab(t_swap *e)
{
	int		i;

	i = 0;
	while (i < e->nb_max)
	{
		printf("a = [%d] | b = [%d]\n", e->tab[i], e->buff[i]);
		i++;
	}
}

int				main(int ac, char **av)
{
	t_swap	*e;
	int		i;

	if (ac < 2)
		return (0);
	e = init_struct(ac);
	e->nb_max = ac - 1;
	check_numbers(ac, av);
	i = -1;
	while (++i < ac - 1)
	{
		e->tab[i] = ft_atoi(av[i + 1]);
		e->nba++;
	}
	check_double(e);
	algo(e);
//	aff_tab(e);
	printf("%d\n", e->count);
	printf("sa = %d, sb = %d, pa = %d, pb = %d, ra = %d, rb = %d, rra = %d, rrb = %d\n", e->sa, e->sb, e->pa, e->pb, e->ra, e->rb, e->rra, e->rrb);
	return (1);
}
