/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:42:03 by alia              #+#    #+#             */
/*   Updated: 2025/04/16 18:40:52 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_player(t_data *g)
{
	g->player.pos_x = g->map->start_x + 0.5;
	g->player.pos_y = g->map->start_y + 0.5;
	if (g->map->player_orientation == 'N')
	{
		g->player.plane_x = 0;
		g->player.plane_y = 0.66;
		g->player.dir_x = -1;
		g->player.dir_y = 0;
	}
	else if (g->map->player_orientation == 'S')
	{
		g->player.plane_x = 0;
		g->player.plane_y = -0.66;
		g->player.dir_x = 1;
		g->player.dir_y = 0;
	}
	else if (g->map->player_orientation == 'W')
		assign_player_we_values(g, -0.66, -1);
	else if (g->map->player_orientation == 'E')
		assign_player_we_values(g, 0.66, 1);
}

t_img	init_img_to_square(t_data *g, char *path)
{
	t_img	texture;
	int		height;
	int		width;
	int		t[2];

	texture.img = mlx_xpm_file_to_image(g->mlx_ptr, path, &width, &height);
	if (!texture.img)
		exit_free_all(g, "Failed to init texture image\n", 1);
	if (height > width)
		height = width;
	else
		width = height;
	if (height > 1000)
		exit_free_all(g, "Image too big\n", 1);
	texture.height = height;
	texture.width = width;
	texture.address = mlx_get_data_addr(texture.img, &t[0], &t[1], &t[2]);
	texture.pixels = (t_color *)texture.address;
	return (texture);
}

t_img	init_screen(t_data *g)
{
	t_img	screen;
	int		t[2];

	screen.img = mlx_new_image(g->mlx_ptr, g->win_height, g->win_width);
	if (!screen.img)
		exit_free_all(g, "Failed to init screen image\n", 1);
	screen.height = g->win_height;
	screen.width = g->win_width;
	screen.address = mlx_get_data_addr(screen.img, &t[0], &t[1], &t[2]);
	screen.pixels = (t_color *)screen.address;
	return (screen);
}

t_color	init_color(int red, int green, int blue)
{
	t_color	color;

	color.r = red;
	color.g = green;
	color.b = blue;
	color.a = 0;
	return (color);
}

void	init_and_launch(t_map *map)
{
	t_data	g;

	g.map = map;
	g.window.img = NULL;
	g.textures[0].img = NULL;
	g.textures[1].img = NULL;
	g.textures[2].img = NULL;
	g.textures[3].img = NULL;
	init_player(&g);
	g.floor = init_color(g.map->floor_blue, g.map->floor_green,
			g.map->floor_red);
	g.ceiling = init_color(g.map->ceiling_blue, g.map->ceiling_green,
			g.map->ceiling_red);
	manage_window(&g);
}
