/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoach <scoach@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:56:10 by snuts             #+#    #+#             */
/*   Updated: 2022/03/26 17:10:45 by scoach           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	key_hook_turn_l(t_raycast *raycast)
{
	float	olddir_x;
	float	oldplane_x;

	olddir_x = raycast->dir_x;
	raycast->dir_x = raycast->dir_x * cos(-raycast->rot_speed)
		- raycast->dir_y * sin(-raycast->rot_speed);
	raycast->dir_y = olddir_x * sin(-raycast->rot_speed)
		+ raycast->dir_y * cos(-raycast->rot_speed);
	oldplane_x = raycast->plane_x;
	raycast->plane_x = raycast->plane_x * cos(-raycast->rot_speed)
		- raycast->plane_y * sin(-raycast->rot_speed);
	raycast->plane_y = oldplane_x * sin(-raycast->rot_speed)
		+ raycast->plane_y * cos(-raycast->rot_speed);
}

void	key_hook_turn_r(t_raycast *raycast)
{
	float	olddir_x;
	float	oldplane_x;

	olddir_x = raycast->dir_x;
	raycast->dir_x = raycast->dir_x * cos(raycast->rot_speed)
		- raycast->dir_y * sin(raycast->rot_speed);
	raycast->dir_y = olddir_x * sin(raycast->rot_speed)
		+ raycast->dir_y * cos(raycast->rot_speed);
	oldplane_x = raycast->plane_x;
	raycast->plane_x = raycast->plane_x * cos(raycast->rot_speed)
		- raycast->plane_y * sin(raycast->rot_speed);
	raycast->plane_y = oldplane_x * sin(raycast->rot_speed)
		+ raycast->plane_y * cos(raycast->rot_speed);
}

void	key_hook_space(t_data *data)
{
	if (data->raycast->main->map[(int)(data->raycast->pos_x
			+ data->raycast->dir_x * 1.0f)][(int) data->raycast->pos_y] == 'C')
		data->raycast->main->map[(int)(data->raycast->pos_x
				+ data->raycast->dir_x * 1.0f)][(int) data->raycast->pos_y]
			= 'O';
	else if (data->raycast->main->map[(int)(data->raycast->pos_x
			+ data->raycast->dir_x * 1.0f)][(int) data->raycast->pos_y] == 'O')
		data->raycast->main->map[(int)(data->raycast->pos_x
				+ data->raycast->dir_x * 1.0f)][(int) data->raycast->pos_y]
			= 'C';
}
