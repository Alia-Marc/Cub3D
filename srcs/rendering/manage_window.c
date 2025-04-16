/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:43:07 by emfourni          #+#    #+#             */
/*   Updated: 2025/04/16 16:49:18 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// int	on_keypress(int keysym, t_data *data)
// {
// 	if (keysym == 65307)
// 		mlx_loop_end(data->mlx_ptr);
// 	// else if (keysym == KEY_W)
//     //     player_move(keysym, data);
//     // else if (keysym == KEY_A)
//     //     player_move(keysym, data);
//     // else if (keysym == KEY_S)
//     //     player_move(keysym, data);
//     // else if (keysym == KEY_D)
//     //     player_move(keysym, data);
// 	return (0);
// }

static void	*init_window(t_data *data)
{
	void	*win_ptr;

	data->win_width = 1080;
	data->win_height = 1080;
	win_ptr = mlx_new_window(data->mlx_ptr, data->win_width, data->win_height, "TON CUB EN 3D");
	if (!win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		return (free(data->mlx_ptr), NULL);
	}
	return (win_ptr);
}

static void	init_keys(t_data *g)
{
	int i;

	i = 0;
	while (i < 65535)
	{
		g->keys[i] = false;
		i++;
	}
}

void	manage_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit_free_all(data, MLX_POINTER_FAIL, 1);
	data->win_ptr = init_window(data);
	if (!data->win_ptr)
		exit_free_all(data, MLX_POINTER_FAIL, 1);
	data->window = init_screen(data);
	data->textures[0] = init_img_to_square(data, data->map->north_texture_path);
	data->textures[1] = init_img_to_square(data, data->map->south_texture_path);
	data->textures[2] = init_img_to_square(data, data->map->west_texture_path);
	data->textures[3] = init_img_to_square(data, data->map->east_texture_path);
	init_keys(data);
	hooks(data);
	mlx_loop(data->mlx_ptr);
	exit_free_all(data, "Exited successfully\n", 0);
}
