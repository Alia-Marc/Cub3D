/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliam <aliam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:42:36 by aliam             #+#    #+#             */
/*   Updated: 2025/04/20 03:00:50 by aliam            ###   ########.fr       */
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

// void	draw_sprites(t_data *g, double *ZBuffer)
// {

// }
