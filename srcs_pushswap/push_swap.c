/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 05:43:30 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/02 05:46:54 by abassibe         ###   ########.fr       */
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

static t_swap	*init_struct(int ac, int visu)
{
	t_swap	*e;

	if (!(e = (t_swap *)ft_memalloc(sizeof(t_swap))))
		ft_error("error malloc");
	if (!(e->tab = (int *)ft_memalloc(sizeof(int) * ac)))
		ft_error("error malloc");
	if (!(e->buff = (int *)ft_memalloc(sizeof(int) * ac)))
		ft_error("error malloc");
	if (visu == 1)
	{
		e->mlx = mlx_init();
		e->win = mlx_new_window(e->mlx, 1200, 1000, "Push_swap");
		e->vimg = mlx_new_image(e->mlx, 1200, 1000);
		e->img = mlx_get_data_addr(e->vimg, &e->bpp, &e->sl, &e->end);
		e->visu = 1;
	}
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

void			check_str_numbers(t_swap **e, char *str)
{
	char		**tab;
	long int	tmp;
	int			i;

	i = 0;
	tab = ft_strsplit(str, ' ');
	while (tab[i])
		i++;
	*e = init_struct(i, 1);
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
	int		i;

	i = -1;
	e = NULL;
	if (ac < 2)
		return (0);
	if (av[1][0] == '-' && av[1][1] == 'v')
	{
		if (ac > 3)
		{
			e = init_struct(ac, 1);
			e->nb_max = ac - 2;
			check_numbers(ac - 1, ++av);
			while (++i < ac - 2)
			{
				e->tab[i] = ft_atoi(av[i + 1]);
				e->nba++;
			}
		}
		else
			check_str_numbers(&e, av[2]);
	}
	else
	{
		if (ac > 3)
		{
			e = init_struct(ac, 0);
			e->nb_max = ac - 1;
			check_numbers(ac, av);
			while (++i < ac - 1)
			{
				e->tab[i] = ft_atoi(av[i + 1]);
				e->nba++;
			}
		}
		else
			check_str_numbers(&e, av[1]);
	}
	check_double(e);
	algo(e);
	return (1);
}
