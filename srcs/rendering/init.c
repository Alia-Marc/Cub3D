/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:42:03 by alia              #+#    #+#             */
/*   Updated: 2025/04/09 18:21:39 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

//char *map1[] = {"111111", "100101","100001","111111"};

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
	{
		g->player.plane_x = -0.66;
		g->player.plane_y = 0;
		g->player.dir_x = 0;
		g->player.dir_y = -1;
	}
	else if (g->map->player_orientation == 'E')
	{
		g->player.plane_x = 0.66;
		g->player.plane_y = 0;
		g->player.dir_x = 0;
		g->player.dir_y = 1;
	}
	//printf("pposx %f, pposy %f,  ", g->player.pos_x, g->player.pos_y);
}

t_img	init_img_to_square(t_data *g, char *path)
{
	t_img	texture;
	int		height;
	int		width;
	int		t[2];

	texture.img = mlx_xpm_file_to_image(g->mlx_ptr, path, &width, &height);
	if (!texture.img)
	{
		ft_printf("error init img");
		exit(1);
		//clean_exit();
	}
	if (height > width)
		height = width;
	else
		width = height;
	if (height > 1000)
	{
		ft_printf("error img too big");
		exit(1);
		//clean_exit();
	}
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
	{
		ft_printf("window img error\n");
		exit(0);
	}
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
	t_data g;

	g.map = map;
	init_player(&g);
	data->floor = init_color(data->map->floor_red, data->map->floor_green, data->map->floor_blue);
	data->ceiling = init_color(data->map->ceiling_red, data->map->ceiling_green, data->map->ceiling_blue);
	printf("%d %d %d, %d %d %d \n", data->floor.r, data->floor.g, data->floor.b, data->map->ceiling_red, data->map->ceiling_green, data->map->ceiling_blue);
	manage_window(&g);
}