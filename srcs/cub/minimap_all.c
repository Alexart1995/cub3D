/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snuts <snuts@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:36:49 by scoach            #+#    #+#             */
/*   Updated: 2022/03/28 21:48:36 by snuts            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static void	draw_minimap_wall(t_data *data, int ym, int xm)
{
	int		yp;
	int		ys;
	int		xp;
	int		xs;

	yp = ym + 8;
	ys = ym;
	while (ys < yp)
	{
		xp = xm + 8;
		xs = xm;
		while (xs < xp)
		{
			my_mlx_pixel_put(data->raycast->minimap, xs, ys, 0xFFFFFF);
			xs++;
		}
		ys++;
	}
}

static void	draw_minimap_player(t_data *data, int ym, int xm)
{
	int		yp;
	int		ys;
	int		xp;
	int		xs;

	yp = ym + 8;
	ys = ym;
	while (ys < yp)
	{
		xp = xm + 8;
		xs = xm;
		while (xs < xp)
		{
			my_mlx_pixel_put(data->raycast->minimap, xs, ys, 0xDF0C0C);
			xs++;
		}
		ys++;
	}
}

static void	draw_minimap_door_opened(t_data *data, int ym, int xm)
{
	int		yp;
	int		ys;
	int		xp;
	int		xs;

	yp = ym + 8;
	ys = ym;
	while (ys < yp)
	{
		xp = xm + 8;
		xs = xm;
		while (xs < xp)
		{
			my_mlx_pixel_put(data->raycast->minimap, xs, ys, 0x036FC0E);
			xs++;
		}
		ys++;
	}
}

static void	draw_minimap_door_closed(t_data *data, int ym, int xm)
{
	int		yp;
	int		ys;
	int		xp;
	int		xs;

	yp = ym + 8;
	ys = ym;
	while (ys < yp)
	{
		xp = xm + 8;
		xs = xm;
		while (xs < xp)
		{
			my_mlx_pixel_put(data->raycast->minimap, xs, ys, 0xFFFF00);
			xs++;
		}
		ys++;
	}
}

void	draw_minimap_all(t_data *data, int ym, int i)
{
	int		xm;
	int		j;

	while (ym < SCREENH / 6 && data->map[i] != NULL)
	{
		xm = 0;
		j = 0;
		while (xm < SCREENW / 6 && data->map[i][j] != '\0')
		{
			if (data->map[i][j] == '1')
				draw_minimap_wall(data, ym, xm);
			else if (i == (int) data->raycast->pos_x
				&& j == (int) data->raycast->pos_y)
				draw_minimap_player(data, ym, xm);
			else if (data->map[i][j] == 'O')
				draw_minimap_door_opened(data, ym, xm);
			else if (data->map[i][j] == 'C')
				draw_minimap_door_closed(data, ym, xm);
			xm += 8;
			j++;
		}
		ym += 8;
		i++;
	}	
}
