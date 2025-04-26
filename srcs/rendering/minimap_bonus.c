/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliam <aliam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 02:28:36 by aliam             #+#    #+#             */
/*   Updated: 2025/04/26 03:59:25 by aliam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_img	init_minimap(t_data *g)
{
	t_img	minimap;
	int		size;

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

void	choose_color_and_draw(double *map, int pos_y, int pos_x, t_data *g)
{
	if ((map[0] < 0 || map[1] < 0 || map[0] > g->map->nb_rows
			|| map[1] > ft_strlen(g->map->map[(int)map[0]]))
		|| ft_check_charset("1 ", g->map->map[(int)map[0]][(int)map[1]]))
		g->minimap.pixels[pos_y * g->minimap.width + pos_x] = 0x000000;
	else if ((g->map->map[(int)map[0]][(int)map[1]]) == 'D')
		g->minimap.pixels[pos_y * g->minimap.width + pos_x] = 0x808080;
	else if ((g->map->map[(int)map[0]][(int)map[1]]) == 'O')
		g->minimap.pixels[pos_y * g->minimap.width + pos_x] = 0x0080FF;
	else
		g->minimap.pixels[pos_y * g->minimap.width + pos_x] = 0xFFFFFF;
}

void	minimap(t_data *g, int pos_y, int pos_x)
{
	double	map[2];
	char	*position;

	map[0] = g->player.pos_x - 5;
	while (pos_y < g->minimap.height)
	{
		pos_x = 2;
		map[1] = g->player.pos_y - 5 + pos_y / 204;
		while (pos_x < g->minimap.width)
		{
			choose_color_and_draw(map, pos_y, pos_x, g);
			pos_x++;
			map[1] += 0.05;
		}
		pos_y++;
		map[0] += 0.05;
	}
	(print_player_pos(g), print_outer_layer(g));
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->minimap.img, 50, 50);
	position = malloc(sizeof(g->player.pos_x) + sizeof(g->player.pos_y) + 15);
	if (!position)
		exit_free_all(g, "Malloc error\n", 1);
	sprintf(position, "x : %f     y : %f", g->player.pos_x, g->player.pos_y);
	mlx_string_put(g->mlx_ptr, g->win_ptr, 64, 40, 0x00FF00, position);
	free(position);
}
