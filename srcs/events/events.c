/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:30:34 by alia              #+#    #+#             */
/*   Updated: 2025/04/09 18:47:50 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	update(t_data *g)
{
	draw_floor_and_ceiling(g);
	dda(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->window.img, 0, 0);
	return (0);
}

int	handle_keypress(int keycode, t_data *g)
{
	if (keycode == XK_Escape)
		exit_free_all(g, "Exited successfully\n", 0);
	return (0);
}

int	handle_keyrelease(int keycode, void *g)
{
	return (0);
}

int	exit_game(t_data *g)
{
	//exit_free_all(g, "Exited successfully\n", 0);
	return (0);
}