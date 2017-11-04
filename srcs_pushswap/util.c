/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 02:30:55 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/04 02:51:38 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_error(const char *str)
{
	ft_fprintf(2, "%s\n", str);
	exit(0);
}

t_swap	*init_struct(const int ac, const int visu)
{
	t_swap		*e;

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
	}
	return (e);
}

void	check_str_numbers(t_swap **e, const char *str, const int visu)
{
	char		**tab;
	long int	tmp;
	int			i;

	i = 0;
	tab = ft_strsplit(str, ' ');
	while (tab[i])
		i++;
	if (visu == 1)
	{
		*e = init_struct(i, 1);
		(*e)->visu = 1;
	}
	else
		*e = init_struct(i, 0);
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

void	rev_rot_ab(t_swap *e)
{
	int			tmp;
	int			i;

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
	write(1, "rrr\n", 4);
}

int		get_target(t_swap *e)
{
	int		i;
	int		closer;
	int		ret;

	i = -1;
	closer = 2147483647;
	while (++i < e->nbb)
		if (ft_abs(e->tab[0] - e->buff[i]) < closer)
		{
			closer = ft_abs(e->tab[0] - e->buff[i]);
			ret = e->buff[i];
		}
	return (ret);
}
