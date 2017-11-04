/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 01:17:48 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/04 02:08:21 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	draw(t_swap *e, const int x, const int y, const int color)
{
	int		i;
	char	red;
	char	green;
	char	blue;

	red = color >> 16;
	green = (color << 8) >> 16;
	blue = (color << 16) >> 16;
	i = x + y;
	if (i > 4800000)
		return ;
	e->img[i] = red;
	e->img[i + 1] = green;
	e->img[i + 2] = blue;
	e->img[i + 3] = 0;
}

void	draw_a(t_swap *e)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	k = 9600;
	while (++i < e->nba)
	{
		while (++j < e->tab[i])
			draw(e, j * 4, k, 0xFFFFFF);
		j = -1;
		k += 9600;
	}
}

void	draw_b(t_swap *e)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	k = 9600;
	while (++i < e->nbb)
	{
		while (++j < e->buff[i])
			draw(e, (j + 610) * 4, k, 0xFFFFFF);
		j = -1;
		k += 9600;
	}
}

void	visu(t_swap *e)
{
	int		i;

	i = -1;
	mlx_destroy_image(e->mlx, e->vimg);
	e->vimg = mlx_new_image(e->mlx, 1200, 1000);
	mlx_get_data_addr(e->vimg, &e->bpp, &e->sl, &e->end);
	while (++i < 1000)
		draw(e, 2400, i * 4800, 0x0000FF);
	draw_a(e);
	draw_b(e);
	mlx_put_image_to_window(e->mlx, e->win, e->vimg, 0, 0);
	mlx_do_sync(e->mlx);
}
