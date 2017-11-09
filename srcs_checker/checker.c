/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 04:12:16 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/09 01:05:15 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void		check_numbers(const int ac, char **av)
{
	int		i;
	int		j;

	i = -1;
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

static void		initiate(t_swap **e, const int ac, char **av)
{
	int		i;

	i = -1;
	*e = init_struct(ac);
	(*e)->nb_max = ac - 1;
	check_numbers(ac - 1, ++av);
	while (++i < ac - 1)
	{
		(*e)->tab[i] = ft_atoi(av[i]);
		(*e)->nba++;
	}
}

static void		check_str_numbers(t_swap **e, const char *str)
{
	char		**tab;
	long int	tmp;
	int			i;

	i = 0;
	while (str[i] != '\0' && ((str[i] >= '0' &&
					str[i] <= '9') || str[i] == ' '))
		i++;
	if (str[i] != '\0')
		ft_error("error");
	i = 0;
	tab = ft_strsplit(str, ' ');
	while (tab[i])
		i++;
	*e = init_struct(i);
	i = -1;
	while (tab[++i])
	{
		tmp = ft_atoi_long(tab[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			ft_error("error");
		(*e)->tab[i] = tmp;
		(*e)->nb_max++;
		(*e)->nba++;
	}
}

int				main(int ac, char **av)
{
	t_swap	*e;
	char	*str;

	if (ac < 2)
		ft_error("error");
	if (ac > 2)
		initiate(&e, ac, av);
	else
		check_str_numbers(&e, av[1]);
	check_double(e);
	while (get_next_line(0, &str))
		do_op(e, str);
	check_sort(e);
	return (1);
}
