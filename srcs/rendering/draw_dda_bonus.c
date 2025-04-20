/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dda_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliam <aliam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:18:30 by malia             #+#    #+#             */
/*   Updated: 2025/04/21 01:07:35 by aliam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	dda(t_data *g)
{
	int		x;
	t_img	texture;
	bool	opened_door;
	double	*Z_Buffer;

	x = 0;
	Z_Buffer = (double *)ft_calloc(g->win_width, sizeof(double));
	if (!Z_Buffer)
		exit_free_all(g, "Malloc error\n", 1);
	while (x < g->win_width)
	{
		opened_door = false;
		calculate_ray_dir(g, x);
		init_dda(g);
		perform_dda_bonus(g, &opened_door);
		calculate_draw_limits(g);
		texture = choose_wall_texture(g);
		draw_vertical_line(g, texture, x);
		Z_Buffer[x] = g->dda.perp_wall_dist;
		draw_opened_door(g, x, &opened_door, texture);
		x++;
	}
	//draw_sprites(g, Z_Buffer);
	free(Z_Buffer);
}

t_img	choose_wall_texture(t_data *g)
{
	t_img	texture;

	if (g->dda.door[0])
		texture = g->door[0];
	else if (g->dda.door[1])
		texture = g->door[1];
	else if (!g->dda.side && g->dda.ray_dir_x >= 0)
		texture = g->textures[0];
	else if (!g->dda.side && g->dda.ray_dir_x < 0)
		texture = g->textures[1];
	else if (g->dda.side && g->dda.ray_dir_y >= 0)
		texture = g->textures[2];
	else if (g->dda.side && g->dda.ray_dir_y < 0)
		texture = g->textures[3];
	return (texture);
}

static void	draw_line(t_data *g, t_img texture, int pos_x, int tex_x)
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
				&& pos_y < g->win_height)
				g->window.pixels[pos_y * g->window.width + pos_x]
					= texture.pixels[texture.height * tex_y + tex_x];
		}
		tex_pos += step;
		pos_y++;
	}
}

void	draw_vertical_line(t_data *g, t_img texture, int x)
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
	draw_line(g, texture, pos_x, tex_x);
}

void	draw_floor_and_ceiling(t_data *g)
{
	int		pos_y;
	bool	floor;
	int		pos_x;

	pos_y = 0;
	floor = false;
	while (pos_y < g->win_height)
	{
		if (!floor && pos_y > g->win_height / 2)
			floor = true;
		pos_x = 0;
		while (pos_x < g->win_width)
		{
			if (floor)
				g->window.pixels[pos_y * g->window.width + pos_x] = g->floor;
			else
				g->window.pixels[pos_y * g->window.width + pos_x] = g->ceiling;
			pos_x++;
		}
		pos_y++;
	}
}
