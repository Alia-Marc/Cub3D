/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliam <aliam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:42:03 by alia              #+#    #+#             */
/*   Updated: 2025/04/21 01:03:21 by aliam            ###   ########.fr       */
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

	texture.img = mlx_xpm_file_to_image(g->mlx_ptr, path, &width, &height);
	if (!texture.img)
		exit_free_all(g, "Failed to init texture image\n", 1);
	if (height > width)
		height = width;
	else
		width = height;
	if (height > 1000)
	{
		mlx_destroy_image(g->mlx_ptr, texture.img);
		exit_free_all(g, "Image too big\n", 1);
	}
	texture.height = height;
	texture.width = width;
	texture.address = mlx_get_data_addr(texture.img, &texture.bits_per_pixel,
			&texture.size_line, &texture.endian);
	texture.pixels = (int *)texture.address;
	return (texture);
}

t_img	init_screen(t_data *g)
{
	t_img	screen;

	screen.img = mlx_new_image(g->mlx_ptr, g->win_width, g->win_height);
	if (!screen.img)
		exit_free_all(g, "Failed to init screen image\n", 1);
	screen.width = g->win_width;
	screen.height = g->win_height;
	screen.address = mlx_get_data_addr(screen.img, &screen.bits_per_pixel,
			&screen.size_line, &screen.endian);
	screen.pixels = (int *)screen.address;
	return (screen);
}

void	init_colors(t_data *g)
{
	g->floor = (g->map->floor_red & 0x0FF) << 16;
	g->floor |= (g->map->floor_green & 0x0FF) << 8;
	g->floor |= (g->map->floor_blue & 0x0FF);
	g->ceiling = (g->map->ceiling_red & 0x0FF) << 16;
	g->ceiling |= (g->map->ceiling_green & 0x0FF) << 8;
	g->ceiling |= (g->map->ceiling_blue & 0x0FF);
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
	g.minimap.img = NULL;
	g.campfire[0].img = NULL;
	g.campfire[1].img = NULL;
	g.campfire[2].img = NULL;
	g.campfire[3].img = NULL;
	g.minimap_on = -1;
	g.door[0].img = NULL;
	g.door[1].img = NULL;
	g.sprites = NULL;
	g.num_sprites = 0;
	g.framecount = 0;
	init_player(&g);
	init_colors(&g);
	manage_window(&g);
}
