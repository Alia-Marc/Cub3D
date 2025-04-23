/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliam <aliam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 00:25:06 by aliam             #+#    #+#             */
/*   Updated: 2025/04/21 01:18:41 by aliam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_img	init_sprite_img(t_data *g, char *path)
{
	t_img	spr;

	spr.img = mlx_xpm_file_to_image(g->mlx_ptr, path, &spr.width, &spr.height);
	if (!spr.img)
		exit_free_all(g, "Failed to init sprite image\n", 1);
	spr.address = mlx_get_data_addr(spr.img, &spr.bits_per_pixel,
			&spr.size_line, &spr.endian);
	spr.pixels = (int *)spr.address;
	return (spr);
}

t_sprite	*create_new_sprite(t_data *g, double pos_x, double pos_y)
{
	t_sprite	*sprite;

	sprite = (t_sprite *)malloc(sizeof(t_sprite));
	if (!sprite)
		exit_free_all(g, "Malloc error\n", 1);
	sprite->pos_x = pos_x;
	sprite->pos_y = pos_y;
	sprite->indice = g->num_sprites;
	sprite->next = NULL;
	return (sprite);
}

t_sprite	*sprites_last(t_sprite *sprites)
{
	while (sprites)
	{
		if (!sprites->next)
			return (sprites);
		sprites = sprites->next;
	}
	return (sprites);
}

void	sprite_add_back(t_sprite **sprites, t_sprite *new)
{
	t_sprite	*tmp;

	if (sprites)
	{
		if (*sprites)
		{
			tmp = sprites_last(*sprites);
			tmp->next = new;
		}
		else
			*sprites = new;
	}
}
