/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_rendering_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliam <aliam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:49:03 by aliam             #+#    #+#             */
/*   Updated: 2025/04/21 05:47:55 by aliam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_sorting_values(t_data *g, t_sprite **sprites, int i)
{
	t_sprite	*tmp;

	g->rendspr.sprite_order = NULL;
	g->rendspr.sprite_distance = NULL;
	g->rendspr.sprite_order = (int *)malloc(sizeof(int) * g->num_sprites);
	if (!g->rendspr.sprite_order)
		exit_free_all(g, "Malloc error\n", 1);
	g->rendspr.sprite_distance = (double *)malloc(sizeof(double)
			* g->num_sprites);
	if (!g->rendspr.sprite_distance)
	{
		free(g->rendspr.sprite_order);
		exit_free_all(g, "Malloc error\n", 1);
	}
	tmp = (*sprites);
	while (i < g->num_sprites)
	{
		g->rendspr.sprite_order[i] = i;
		g->rendspr.sprite_distance[i] = ((g->player.pos_x - tmp->pos_x)
				* (g->player.pos_x - tmp->pos_x)
				+ (g->player.pos_y - tmp->pos_y)
				* (g->player.pos_y - tmp->pos_y));
		tmp = tmp->next;
		i++;
	}
}

void	sort_sprites_distance(t_data *g, int i, int j)
{
	double	tmp_dist;
	int		tmp_indice;

	init_sorting_values(g, &g->sprites, 0);
	while (i < g->num_sprites - 1)
	{
		j = 0;
		while (j < g->num_sprites - i - 1)
		{
			if (g->rendspr.sprite_distance[j]
				< g->rendspr.sprite_distance[j + 1])
			{
				tmp_dist = g->rendspr.sprite_distance[j];
				tmp_indice = g->rendspr.sprite_order[j];
				g->rendspr.sprite_distance[j]
					= g->rendspr.sprite_distance[j + 1];
				g->rendspr.sprite_distance[j + 1] = tmp_dist;
				g->rendspr.sprite_order[j] = g->rendspr.sprite_order[j + 1];
				g->rendspr.sprite_order[j + 1] = tmp_indice;
			}
			j++;
		}
		i++;
	}
}

void	calculate_sprite_position(t_data *g, t_sprite **sprites, int i)
{
	t_sprite	*tmp;

	tmp = (*sprites);
	while (tmp && tmp->indice != i)
		tmp = tmp->next;
	// printf("        (%d)<%d> (%f;%f)", i, tmp->indice, tmp->pos_x, tmp->pos_y);
	g->rendspr.sprite_x = tmp->pos_x - g->player.pos_x;
	g->rendspr.sprite_y = tmp->pos_y - g->player.pos_y;
	g->rendspr.inv_det = 1.0 / (g->player.plane_x * g->player.dir_y
			- g->player.dir_x * g->player.plane_y);
	g->rendspr.transform_x = g->rendspr.inv_det * (g->player.dir_y
			* g->rendspr.sprite_x - g->player.dir_x * g->rendspr.sprite_y);
	g->rendspr.transform_y = g->rendspr.inv_det * (-g->player.plane_y
			* g->rendspr.sprite_x + g->player.plane_x * g->rendspr.sprite_y);
	g->rendspr.sprite_screen_x = (int)((g->win_width / 2)
			* (1 + g->rendspr.transform_x / g->rendspr.transform_y));
	g->rendspr.v_move_screen = (int)(VMove / g->rendspr.transform_y);
}

void	calculate_sprite_size(t_data *g)
{
	g->rendspr.sprite_height = abs((int)(g->win_height
				/ (g->rendspr.transform_y))) / VDiv;
	g->rendspr.draw_start_y = -g->rendspr.sprite_height / 2
		+ g->win_height / 2 + g->rendspr.v_move_screen;
	if (g->rendspr.draw_start_y < 0)
		g->rendspr.draw_start_y = 0;
	g->rendspr.draw_end_y = g->rendspr.sprite_height / 2
		+ g->win_height / 2 + g->rendspr.v_move_screen;
	if (g->rendspr.draw_end_y >= g->win_height)
		g->rendspr.draw_end_y = g->win_height - 1;
	g->rendspr.sprite_width = abs((int)(g->win_height
				/ (g->rendspr.transform_y))) / UDiv;
	g->rendspr.draw_start_x = -g->rendspr.sprite_width
		/ 2 + g->rendspr.sprite_screen_x;
	if (g->rendspr.draw_start_x < 0)
		g->rendspr.draw_start_x = 0;
	g->rendspr.draw_end_x = g->rendspr.sprite_width
		/ 2 + g->rendspr.sprite_screen_x;
	if (g->rendspr.draw_end_x >= g->win_width)
		g->rendspr.draw_end_x = g->win_width - 1;
}
