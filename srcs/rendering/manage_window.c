/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:43:07 by emfourni          #+#    #+#             */
/*   Updated: 2025/03/28 15:49:46 by marc             ###   ########.fr       */
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

	win_ptr = mlx_new_window(data->mlx_ptr, 1024, 1024, "TON CUB EN 3D");
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
	hooks(data);
	mlx_loop(data->mlx_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
}
