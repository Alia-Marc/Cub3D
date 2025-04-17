/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:03:52 by malia             #+#    #+#             */
/*   Updated: 2025/04/17 20:28:11 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	handle_mouse_mouvement(int x, int y, t_data *g)
{
	static int	last_mouse_x_position = -1;
	double		new_rot_speed;
	double		old_dir_x;
	double		old_plane_x;

	(void)y;
	if (last_mouse_x_position < 0)
		last_mouse_x_position = x;
	new_rot_speed = (x - last_mouse_x_position) * ROT_SPEED / 25;
	last_mouse_x_position = x;
	old_dir_x = g->player.dir_x;
	g->player.dir_x = g->player.dir_x * cos(-new_rot_speed) - g->player.dir_y
		* sin(-new_rot_speed);
	g->player.dir_y = old_dir_x * sin(-new_rot_speed) + g->player.dir_y
		* cos(-new_rot_speed);
	old_plane_x = g->player.plane_x;
	g->player.plane_x = g->player.plane_x * cos(-new_rot_speed)
		- g->player.plane_y
		* sin(-new_rot_speed);
	g->player.plane_y = old_plane_x * sin(-new_rot_speed) + g->player.plane_y
		* cos(-new_rot_speed);
	mlx_mouse_move(g->mlx_ptr, g->win_ptr,
		g->window.width / 2, g->window.height / 2);
	last_mouse_x_position = g->window.width / 2;
	return (0);
}

void	hooks(t_data *g)
{
	//mlx_mouse_hide(g->mlx_ptr, g->win_ptr); Pour cacher la souris, la fonction leak
	mlx_hook(g->win_ptr, KeyPress, KeyPressMask, handle_keypress, g);
	mlx_hook(g->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease, g);
	mlx_hook(g->win_ptr, DestroyNotify, StructureNotifyMask,
		mlx_loop_end, g->mlx_ptr);
	mlx_hook(g->win_ptr, MotionNotify, PointerMotionMask,
		handle_mouse_mouvement, g);
	mlx_loop_hook(g->mlx_ptr, update, g);
}
