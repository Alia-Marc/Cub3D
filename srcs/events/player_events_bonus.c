/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_events_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliam <aliam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:55:15 by malia             #+#    #+#             */
/*   Updated: 2025/04/20 03:10:41 by aliam            ###   ########.fr       */
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
	if (!ft_check_charset("1D", g->map->map[(int)posx][(int)g->player.pos_y]))
		g->player.pos_x = posx;
	if (!ft_check_charset("1D", g->map->map[(int)g->player.pos_x][(int)posy]))
		g->player.pos_y = posy;
}

void	player_rotation(t_data *g, t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;

	if (g->keys[XK_Right])
	{
		old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(-ROT_SPEED) - p->dir_y * sin(-ROT_SPEED);
		p->dir_y = old_dir_x * sin(-ROT_SPEED) + p->dir_y * cos(-ROT_SPEED);
		old_plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(-ROT_SPEED) - p->plane_y
			* sin(-ROT_SPEED);
		p->plane_y = old_plane_x * sin(-ROT_SPEED) + p->plane_y
			* cos(-ROT_SPEED);
	}
	if (g->keys[XK_Left])
	{
		old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(ROT_SPEED) - p->dir_y * sin(ROT_SPEED);
		p->dir_y = old_dir_x * sin(ROT_SPEED) + p->dir_y * cos(ROT_SPEED);
		old_plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(ROT_SPEED) - p->plane_y * sin(ROT_SPEED);
		p->plane_y = old_plane_x * sin(ROT_SPEED) + p->plane_y * cos(ROT_SPEED);
	}
}

void	player_door_interaction(t_data *g, int keycode)
{
	int	x;
	int	y;

	if (keycode == XK_e)
	{
		x = (int)(g->player.pos_x);
		y = (int)(g->player.pos_y);
		if (g->map->map[(int)(x + 1)][(int)(y)] == 'D')
			g->map->map[(int)(x + 1)][(int)(y)] = 'O';
		else if (g->map->map[(int)(x - 1)][(int)(y)] == 'D')
			g->map->map[(int)(x - 1)][(int)(y)] = 'O';
		else if (g->map->map[(int)(x)][(int)(y + 1)] == 'D')
			g->map->map[(int)(x)][(int)(y + 1)] = 'O';
		else if (g->map->map[(int)(x)][(int)(y - 1)] == 'D')
			g->map->map[(int)(x)][(int)(y - 1)] = 'O';
		else if (g->map->map[(int)(x + 1)][(int)(y)] == 'O')
			g->map->map[(int)(x + 1)][(int)(y)] = 'D';
		else if (g->map->map[(int)(x - 1)][(int)(y)] == 'O')
			g->map->map[(int)(x - 1)][(int)(y)] = 'D';
		else if (g->map->map[(int)(x)][(int)(y + 1)] == 'O')
			g->map->map[(int)(x)][(int)(y + 1)] = 'D';
		else if (g->map->map[(int)(x)][(int)(y - 1)] == 'O')
			g->map->map[(int)(x)][(int)(y - 1)] = 'D';
	}
}
