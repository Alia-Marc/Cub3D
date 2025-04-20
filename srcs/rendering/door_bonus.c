/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliam <aliam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 23:51:48 by aliam             #+#    #+#             */
/*   Updated: 2025/04/20 20:53:10 by aliam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	hit_wall_or_door(t_data *g, int *hit, bool *opened_door)
{
	if (ft_check_charset("1DO", g->map->map[g->dda.map_x][g->dda.map_y]))
	{
		*hit = 1;
		if (g->map->map[g->dda.map_x][g->dda.map_y] == 'D')
			g->dda.door[0] = true;
		else if (g->map->map[g->dda.map_x][g->dda.map_y] == 'O')
		{
			*opened_door = true;
			*hit = 0;
		}
	}
}

void	hit_wall_or_opened_door(t_data *g, int *hit)
{
	if (ft_check_charset("1OD", g->map->map[g->dda.map_x][g->dda.map_y]))
	{
		*hit = 1;
		if (g->map->map[g->dda.map_x][g->dda.map_y] == 'O')
			g->dda.door[1] = true;
		else if (g->map->map[g->dda.map_x][g->dda.map_y] == 'D')
			g->dda.door[0] = true;
	}
}

void	perform_opened_door_dda(t_data *g)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (g->dda.side_dist_x < g->dda.side_dist_y)
		{
			g->dda.side_dist_x += g->dda.delta_dist_x;
			g->dda.map_x += g->dda.step_x;
			g->dda.side = 0;
		}
		else
		{
			g->dda.side_dist_y += g->dda.delta_dist_y;
			g->dda.map_y += g->dda.step_y;
			g->dda.side = 1;
		}
		hit_wall_or_opened_door(g, &hit);
	}
	if (!g->dda.side)
		g->dda.perp_wall_dist = (g->dda.side_dist_x - g->dda.delta_dist_x);
	else
		g->dda.perp_wall_dist = (g->dda.side_dist_y - g->dda.delta_dist_y);
}

static void	draw_door_line(t_data *g, t_img texture, int pos_x, int tex_x)
{
	double	step;
	double	tex_pos;
	int		pos_y;
	int		tex_y;

	step = 1.0 * texture.height / g->dda.line_height;
	tex_pos = (g->dda.draw_start - g->win_height / 2
			+ g->dda.line_height / 2) * step;
	pos_y = g->dda.draw_start;
	while (pos_y < g->dda.draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y >= 0 && tex_y < texture.height)
		{
			if (pos_x >= 0 && pos_x < g->win_width && pos_y >= 0
				&& pos_y < g->win_height
				&& texture.pixels[texture.height * tex_y + tex_x] != 0x00FF00)
				g->window.pixels[pos_y * g->window.width + pos_x]
					= texture.pixels[texture.height * tex_y + tex_x];
		}
		tex_pos += step;
		pos_y++;
	}
}

void	draw_door_vertical_line(t_data *g, t_img texture, int x)
{
	int		pos_x;
	int		tex_x;

	if (!g->dda.side)
		g->dda.side_x = g->player.pos_y
			+ g->dda.perp_wall_dist * g->dda.ray_dir_y;
	else
		g->dda.side_x = g->player.pos_x
			+ g->dda.perp_wall_dist * g->dda.ray_dir_x;
	g->dda.side_x -= floor(g->dda.side_x);
	pos_x = x;
	tex_x = (int)(g->dda.side_x * (double)texture.width);
	if (g->dda.side == 0 && g->dda.ray_dir_x > 0)
		tex_x = texture.width - tex_x - 1;
	if (g->dda.side == 1 && g->dda.ray_dir_y < 0)
		tex_x = texture.width - tex_x - 1;
	draw_door_line(g, texture, pos_x, tex_x);
}

// void	init_doors(t_data *g)
// {

// }
