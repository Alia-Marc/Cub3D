/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:42:36 by aliam             #+#    #+#             */
/*   Updated: 2025/04/23 17:59:13 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	add_new_sprite_location(t_data *g, int keycode)
{
	if (keycode == XK_f && g->map->map[(int)g->player.pos_x]
		[(int)g->player.pos_y] != 'O')
	{
		sprite_add_back(&g->sprites,
			create_new_sprite(g, g->player.pos_x, g->player.pos_y));
		g->num_sprites += 1;
	}
}

void	draw_sprite_line(t_data *g, t_img texture, int tex_x, int *y)
{
	int	d;
	int	tex_y;

	d = (*y - g->rendspr.v_move_screen) * 256 - g->win_height * 128
		+ g->rendspr.sprite_height * 128;
	tex_y = (int)((d * texture.height) / g->rendspr.sprite_height) / 256;
	if ((texture.width * tex_y + tex_x) >= 0
		&& texture.pixels[texture.width * tex_y + tex_x] != 0x00FF00)
		g->window.pixels[*y * g->window.width + g->rendspr.stripe]
			= texture.pixels[texture.width * tex_y + tex_x];
	(*y)++;
}

void	draw_sprite_all_lines(t_data *g, double *Z_Buffer, t_img texture)
{
	int	tex_x;
	int	y;

	g->rendspr.stripe = g->rendspr.draw_start_x;
	while (g->rendspr.stripe < g->rendspr.draw_end_x)
	{
		tex_x = (int)((256 * (g->rendspr.stripe - (-g->rendspr.sprite_width
							/ 2 + g->rendspr.sprite_screen_x))
					* texture.height / g->rendspr.sprite_width) / 256);
		if (g->rendspr.transform_y > 0 && g->rendspr.stripe > 0
			&& g->rendspr.stripe < g->win_width && g->rendspr.transform_y
			< Z_Buffer[g->rendspr.stripe])
		{
			y = g->rendspr.draw_start_y;
			while (y < g->rendspr.draw_end_y)
				draw_sprite_line(g, texture, tex_x, &y);
		}
		g->rendspr.stripe++;
	}
}

t_img	choose_animated_texture(t_data *g)
{
	t_img	texture;

	if (g->framecount <= 10)
		texture = g->campfire[0];
	else if (g->framecount > 10 && g->framecount <= 20)
		texture = g->campfire[1];
	else if (g->framecount > 20 && g->framecount <= 30)
		texture = g->campfire[2];
	else if (g->framecount > 30)
		texture = g->campfire[3];
	return (texture);
}

void	draw_sprites(t_data *g, double *Z_Buffer)
{
	int		i;
	t_img	animated_texture;

	i = 0;
	sort_sprites_distance(g, 0, 0);
	animated_texture = choose_animated_texture(g);
	while (i < g->num_sprites)
	{
		calculate_sprite_position(g, &g->sprites, g->rendspr.sprite_order[i]);
		calculate_sprite_size(g);
		draw_sprite_all_lines(g, Z_Buffer, animated_texture);
		i++;
	}
	free(g->rendspr.sprite_order);
	free(g->rendspr.sprite_distance);
}
