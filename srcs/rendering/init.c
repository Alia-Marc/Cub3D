/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:42:03 by alia              #+#    #+#             */
/*   Updated: 2025/04/04 20:25:53 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char *map1[] = {"111111", "100101","100001","111111"};

void	init_and_launch(t_map *map)
{
	t_data g;


	g.map = map;
	g.player.plane_x = 0;
	g.player.plane_y = 0.66;
	g.player.dir_x = -1;
	g.player.dir_y = 0;
	g.player.pos_x = g.map->start_x;
	g.player.pos_y = g.map->start_y;
	manage_window(&g);
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
