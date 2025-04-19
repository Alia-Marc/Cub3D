/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliam <aliam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 02:28:36 by aliam             #+#    #+#             */
/*   Updated: 2025/04/19 05:51:02 by aliam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_img	init_minimap(t_data *g)
{
	t_img	minimap;
	int		size;

	g->minimap_on = -1;
	if (g->win_width < 300 || g->win_height < 300)
	{
		g->minimap_on = 0;
		return (minimap);
	}
	size = 204;
	minimap.img = mlx_new_image(g->mlx_ptr, size, size);
	if (!minimap.img)
		exit_free_all(g, "Failed to init minimap image\n", 1);
	minimap.width = size;
	minimap.height = size;
	minimap.address = mlx_get_data_addr(minimap.img, &minimap.bits_per_pixel,
			&minimap.size_line, &minimap.endian);
	minimap.pixels = (int *)minimap.address;
	return (minimap);
}

void	print_outer_layer(t_data *g)
{
	int	pos_y;
	int	pos_x;

	pos_y = 0;
	while (pos_y < g->minimap.height)
	{
		pos_x = 0;
		while (pos_x < g->minimap.width)
		{
			if (pos_x == 2 && (pos_y > 1 && pos_y < g->minimap.height - 2))
				pos_x = g->minimap.width - 2;
			g->minimap.pixels[pos_y * g->minimap.width + pos_x] = 0xFFD700;
			pos_x++;
		}
		pos_y++;
	}
}

void	print_player_pos(t_data *g)
{
	int	y;
	int	x;

	y = 100;
	while (y <= 104)
	{
		x = 100;
		while (x <= 104)
		{
			g->minimap.pixels[y * g->minimap.width + x] = 0xFF0000;
			x++;
		}
		y++;
	}
}

int	is_wall_or_space(char c)
{
	return (c == '1' || c == ' ');
}

void	minimap(t_data *g, int pos_y, int pos_x)
{
	double	mapx;
	double	mapy;

	mapx = g->player.pos_x - 5;
	while (pos_y < g->minimap.height)
	{
		pos_x = 2;
		mapy = g->player.pos_y - 5 + pos_y / 204;
		while (pos_x < g->minimap.width)
		{
			if ((mapx < 0 || mapy < 0 || mapx > g->map->nb_rows
					|| mapy > ft_strlen(g->map->map[(int)mapx]))
				|| is_wall_or_space(g->map->map[(int)mapx][(int)mapy]))
				g->minimap.pixels[pos_y * g->minimap.width + pos_x] = 0x000000;
			else
				g->minimap.pixels[pos_y * g->minimap.width + pos_x] = 0xFFFFFF;
			pos_x++;
			mapy += 0.05;
		}
		pos_y++;
		mapx += 0.05;
	}
	print_player_pos(g);
	print_outer_layer(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->minimap.img, 50, 50);
}
