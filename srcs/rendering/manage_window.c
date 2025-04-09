/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:43:07 by emfourni          #+#    #+#             */
/*   Updated: 2025/04/09 18:21:33 by malia            ###   ########.fr       */
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

void	manage_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		free_map(data->map);
		ft_printf("Error\n"MLX_POINTER_FAIL);
		exit(1);
	}
	data->win_ptr = init_window(data);
	if (!data->win_ptr)
	{
		free_map(data->map);
		free(data->mlx_ptr);
		ft_printf("Error\n"MLX_POINTER_FAIL);
		exit(1);
	}
	//mlx_hook(data->win_ptr, 17, 0, mlx_loop_end, data->mlx_ptr);
	// mlx_key_hook(data->win_ptr, &on_keypress, &data);
	data->window = init_screen(data);
	//dda(data);
	// dda(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->window.img, 0, 0);
	data->textures[0] = init_img_to_square(data, data->map->north_texture_path);
	data->textures[1] = init_img_to_square(data, data->map->south_texture_path);
	data->textures[2] = init_img_to_square(data, data->map->west_texture_path);
	data->textures[3] = init_img_to_square(data, data->map->east_texture_path);
	hooks(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
