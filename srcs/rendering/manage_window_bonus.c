/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliam <aliam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:43:07 by emfourni          #+#    #+#             */
/*   Updated: 2025/04/20 03:01:30 by aliam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	*init_window(t_data *data)
{
	void	*win_ptr;

	data->win_width = 1920;
	data->win_height = 1080;
	win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height, "TON CUB EN 3D");
	if (!win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		return (free(data->mlx_ptr), NULL);
	}
	return (win_ptr);
}

static void	init_keys(t_data *g)
{
	int	i;

	i = 0;
	while (i < X11_MAX_KEYS)
	{
		g->keys[i] = false;
		i++;
	}
}

void	init_imgs(t_data *g)
{
	g->window = init_screen(g);
	g->textures[0] = init_img_to_square(g, g->map->north_texture_path);
	g->textures[1] = init_img_to_square(g, g->map->south_texture_path);
	g->textures[2] = init_img_to_square(g, g->map->west_texture_path);
	g->textures[3] = init_img_to_square(g, g->map->east_texture_path);
	g->minimap = init_minimap(g);
	g->sprites.campfire[0] = init_sprite_img(g, "./textures/campfire/campfire0_filled.xpm");
	g->sprites.campfire[1] = init_sprite_img(g, "./textures/campfire/campfire1_filled.xpm");
	g->sprites.campfire[2] = init_sprite_img(g, "./textures/campfire/campfire2_filled.xpm");
	g->sprites.campfire[3] = init_sprite_img(g, "./textures/campfire/campfire3_filled.xpm");
	g->door[0] = init_img_to_square(g, "./textures/door/space_door_400_shrinked.xpm");
	g->door[1] = init_img_to_square(g, "./textures/door/space_door_opened_filled_400_2_shrinked.xpm");
}

void	manage_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit_free_all(data, MLX_POINTER_FAIL, 1);
	data->win_ptr = init_window(data);
	if (!data->win_ptr)
		exit_free_all(data, MLX_POINTER_FAIL, 1);
	init_imgs(data);
	init_keys(data);
	hooks(data);
	mlx_loop(data->mlx_ptr);
	exit_free_all(data, "Exited successfully\n", 0);
}
