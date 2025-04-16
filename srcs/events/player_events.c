/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:55:15 by malia             #+#    #+#             */
/*   Updated: 2025/04/16 17:50:30 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	player_movement(t_data *g, double posx, double posy)
{
	if (g->keys[XK_w])
	{
		posx += g->player.dir_x * MOV_SPEED;
		posy += g->player.dir_y * MOV_SPEED;
	}
	if (g->keys[XK_s])
	{
		posx -= g->player.dir_x * MOV_SPEED;
		posy -= g->player.dir_y * MOV_SPEED;
	}
	if (g->keys[XK_d])
	{
		posx += g->player.plane_x * MOV_SPEED;
		posy += g->player.plane_y * MOV_SPEED;
	}
	if (g->keys[XK_a])
	{
		posx -= g->player.plane_x * MOV_SPEED;
		posy -= g->player.plane_y * MOV_SPEED;
	}
	if (g->map->map[(int)posx][(int)g->player.pos_y] != '1')
		g->player.pos_x = posx;
	if (g->map->map[(int)g->player.pos_x][(int)posy] != '1')
		g->player.pos_y = posy;	
}

void	player_rotation(t_data *g)
{
	double	old_dir_x;
	double	old_plane_x;

	if (g->keys[XK_Right])
	{
		old_dir_x = g->player.dir_x;
		g->player.dir_x = g->player.dir_x * cos(-ROT_SPEED) - g->player.dir_y * sin(-ROT_SPEED);
		g->player.dir_y = old_dir_x * sin(-ROT_SPEED) + g->player.dir_y * cos(-ROT_SPEED);
		old_plane_x = g->player.plane_x;
		g->player.plane_x = g->player.plane_x * cos(-ROT_SPEED) - g->player.plane_y * sin(-ROT_SPEED);
		g->player.plane_y = old_plane_x * sin(-ROT_SPEED) + g->player.plane_y * cos(-ROT_SPEED);
	}
	if (g->keys[XK_Left])
	{
		old_dir_x = g->player.dir_x;
		g->player.dir_x = g->player.dir_x * cos(ROT_SPEED) - g->player.dir_y * sin(ROT_SPEED);
		g->player.dir_y = old_dir_x * sin(ROT_SPEED) + g->player.dir_y * cos(ROT_SPEED);
		old_plane_x = g->player.plane_x;
		g->player.plane_x = g->player.plane_x * cos(ROT_SPEED) - g->player.plane_y * sin(ROT_SPEED);
		g->player.plane_y = old_plane_x * sin(ROT_SPEED) + g->player.plane_y * cos(ROT_SPEED);
	}
}
