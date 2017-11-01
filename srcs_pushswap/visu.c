/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 01:17:48 by abassibe          #+#    #+#             */
/*   Updated: 2017/11/01 02:47:55 by abassibe         ###   ########.fr       */
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
	i = (x * 4) + (y * e->sl);
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
	k = 2;
	while (++i < e->nba)
	{
		while (++j < e->tab[i])
			draw(e, j, k, 0xFFFFFF);
		j = -1;
		k += 2;
	}
}

void	draw_b(t_swap *e)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	k = 2;
	while (++i < e->nbb)
	{
		while (++j < e->buff[i])
			draw(e, j + 1010, k, 0xFFFFFF);
		j = -1;
		k += 2;
	}
}

void	clear_img(t_swap *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < 2000)
	{
		while (y < 1000)
		{
			draw(e, x, y, 0x000000);
			y++;
		}
		y = 0;
		x++;
	}
}

void	visu(t_swap *e)
{
	int		i;

	i = -1;
	clear_img(e);
	while (++i < 1000)
		draw(e, 1000, i, 0x0000FF);
	draw_a(e);
	draw_b(e);
	mlx_put_image_to_window(e->mlx, e->win, e->vimg, 0, 0);
	mlx_do_sync(e->mlx);
}
