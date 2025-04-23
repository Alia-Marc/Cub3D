/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliam <aliam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 21:04:59 by aliam             #+#    #+#             */
/*   Updated: 2025/04/20 21:06:35 by aliam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_opened_door(t_data *g, int x, bool *opened_door, t_img texture)
{
	if (*opened_door)
	{
		calculate_ray_dir(g, x);
		init_dda(g);
		perform_opened_door_dda(g);
		calculate_draw_limits(g);
		texture = choose_wall_texture(g);
		draw_door_vertical_line(g, texture, x);
	}
}
