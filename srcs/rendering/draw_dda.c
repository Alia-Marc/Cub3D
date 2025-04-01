/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dda.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 19:18:30 by malia             #+#    #+#             */
/*   Updated: 2025/04/01 19:23:30 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	dda(t_data *g)
{
	int	x;

	x = 0;
	while (x < g->win_width)
	{
		calculate_ray_dir(g, x);
		init_dda(g);
		perform_dda(g);
		calculate_draw_limits(g);
	}
}
