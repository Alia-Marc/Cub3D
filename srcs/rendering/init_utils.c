/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:28:55 by malia             #+#    #+#             */
/*   Updated: 2025/04/16 18:35:36 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	assign_player_we_values(t_data *g, double plane_x, double dir_y)
{
	g->player.plane_x = plane_x;
	g->player.plane_y = 0;
	g->player.dir_x = 0;
	g->player.dir_y = dir_y;
}
