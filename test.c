/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 05:43:30 by abassibe          #+#    #+#             */
/*   Updated: 2017/10/14 02:54:58 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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
		printf("a = [%d] | b = [%d] // i = %d\n", e->tab[i], e->buff[i], i);
		i++;
	}
}

void			algo1(t_swap *e)
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
	aff_tab(e);
}

void			algo(t_swap *e)
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
	e->count++;
	write (1, "rrb\n", 4);
//	dprintf(e->fd, "rev rot b :\n");
	aff_tab(e);
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
	aff_tab(e);
	printf("--------------------------------------------\n");
	check_double(e);
	algo1(e);
	printf("--------------------------------------------\n");
	algo1(e);
	printf("--------------------------------------------\n");
	algo(e);
	printf("--------------------------------------------\n");
	algo(e);
	return (1);
}
