/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:27:18 by alia              #+#    #+#             */
/*   Updated: 2025/03/14 17:49:19 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	hooks(t_data *g)
{
	mlx_hook(g->win_ptr, KeyPress, KeyPressMask, handle_keypress, g);
    mlx_hook(g->win_ptr, KeyRelease, KeyReleaseMask, handle_keyrelease, g);
	mlx_hook(g->win_ptr, DestroyNotify, StructureNotifyMask, mlx_loop_end, g->mlx_ptr);
	mlx_loop_hook(g->mlx_ptr, handle_no_event, g);
}
