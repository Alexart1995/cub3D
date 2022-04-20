/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:06:28 by snuts             #+#    #+#             */
/*   Updated: 2022/03/26 18:28:01 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

// void	draw_minimap_all(t_data *data, int ym, int i)
// {
// 	int		xm;
// 	int		j;

// 	while (ym < SCREENH / 6 && data->map[i] != NULL)
// 	{
// 		xm = 0;
// 		j = 0;
// 		while (xm < SCREENW / 6 && data->map[i][j] != '\0')
// 		{
// 			if (data->map[i][j] == '1')
// 				draw_minimap_wall(data, ym, xm);
// 			else if (i == (int) data->raycast->pos_x
// 				&& j == (int) data->raycast->pos_y)
// 				draw_minimap_player(data, ym, xm);
// 			else if (data->map[i][j] == 'O')
// 				draw_minimap_door_opened(data, ym, xm);
// 			else if (data->map[i][j] == 'C')
// 				draw_minimap_door_closed(data, ym, xm);
// 			xm += 8;
// 			j++;
// 		}
// 		ym += 8;
// 		i++;
// 	}	
// }

static void	draw_minimap_door_other(t_data *data, int ym, int xm)
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
			my_mlx_pixel_put(data->raycast->minimap, xs, ys, 0x99433f3f);
			xs++;
		}
		ys++;
	}
}

static void	draw_phone(t_data *data)
{
	int		ym;
	int		xm;

	ym = 0;
	while (ym < SCREENH / 6)
	{
		xm = 0;
		while (xm < SCREENW / 6)
		{
			draw_minimap_door_other(data, ym, xm);
			xm += 8;
		}
		ym += 8;
	}
}

void	draw_minimap(t_data *data)
{
	int		ym;
	int		i;

	draw_phone(data);
	ym = 0;
	i = 0;
	draw_minimap_all(data, ym, i);
}
