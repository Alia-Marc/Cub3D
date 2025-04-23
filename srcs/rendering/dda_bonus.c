/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliam <aliam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:01:18 by malia             #+#    #+#             */
/*   Updated: 2025/04/20 20:51:12 by aliam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	calculate_ray_dir(t_data *g, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)g->win_width - 1;
	g->dda.ray_dir_x = g->player.dir_x + g->player.plane_x * camera_x;
	g->dda.ray_dir_y = g->player.dir_y + g->player.plane_y * camera_x;
	g->dda.door[0] = false;
	g->dda.door[1] = false;
}

void	calculate_side_dist(t_data *g)
{
	if (g->dda.ray_dir_x < 0)
	{
		g->dda.step_x = -1;
		g->dda.side_dist_x = (g->player.pos_x - g->dda.map_x)
			* g->dda.delta_dist_x;
	}
	else
	{
		g->dda.step_x = 1;
		g->dda.side_dist_x = (g->dda.map_x + 1.0 - g->player.pos_x)
			* g->dda.delta_dist_x;
	}
	if (g->dda.ray_dir_y < 0)
	{
		g->dda.step_y = -1;
		g->dda.side_dist_y = (g->player.pos_y - g->dda.map_y)
			* g->dda.delta_dist_y;
	}
	else
	{
		g->dda.step_y = 1;
		g->dda.side_dist_y = (g->dda.map_y + 1.0 - g->player.pos_y)
			* g->dda.delta_dist_y;
	}
}

void	init_dda(t_data *g)
{
	g->dda.map_x = (int)g->player.pos_x;
	g->dda.map_y = (int)g->player.pos_y;
	if (g->dda.ray_dir_x == 0)
		g->dda.delta_dist_x = 1e30;
	else
		g->dda.delta_dist_x = fabs(1 / g->dda.ray_dir_x);
	if (g->dda.ray_dir_y == 0)
		g->dda.delta_dist_y = 1e30;
	else
		g->dda.delta_dist_y = fabs(1 / g->dda.ray_dir_y);
	calculate_side_dist(g);
}

void	perform_dda_bonus(t_data *g, bool *opened_door)
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
		hit_wall_or_door(g, &hit, opened_door);
	}
	if (!g->dda.side)
		g->dda.perp_wall_dist = (g->dda.side_dist_x - g->dda.delta_dist_x);
	else
		g->dda.perp_wall_dist = (g->dda.side_dist_y - g->dda.delta_dist_y);
}

void	calculate_draw_limits(t_data *g)
{
	g->dda.line_height = (int)(g->win_height / g->dda.perp_wall_dist);
	g->dda.draw_start = -g->dda.line_height / 2 + g->win_height / 2;
	if (g->dda.draw_start < 0)
		g->dda.draw_start = 0;
	g->dda.draw_end = g->dda.line_height / 2 + g->win_height / 2;
	if (g->dda.draw_end >= g->win_height)
		g->dda.draw_end = g->win_height - 1;
}
