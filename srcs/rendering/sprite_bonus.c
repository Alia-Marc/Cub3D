/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliam <aliam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:42:36 by aliam             #+#    #+#             */
/*   Updated: 2025/04/21 01:07:37 by aliam            ###   ########.fr       */
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

void	print_sprites_location(t_data *g, t_sprite **sprites)
{
	t_sprite	*tmp;

	if (!sprites)
		return ;
	tmp = (*sprites);
	while (tmp)
	{
		printf("([%d] pos_x = %f, pos_y = %f), ", tmp->indice, tmp->pos_x, tmp->pos_y);
		tmp = tmp->next;
	}
	printf("\n");
	// int	i;
	// while (i < g->num_sprites)
	// {
	// 	printf("TEST([%d] pos_x = %f, pos_y = %f), ", i, (*sprites)[i].pos_x, (*sprites)[i].pos_y);
	// 	i++;
	// }
	// printf("\n");
}

void	add_new_sprite_location(t_data *g, int keycode)
{
	if (keycode == XK_f)
	{
		sprite_add_back(&g->sprites, 
			create_new_sprite(g, g->player.pos_x, g->player.pos_y));
		g->num_sprites += 1;
		print_sprites_location(g, &g->sprites);
	}
}

// void	draw_sprites(t_data *g, double *Z_Buffer)
// {

// }
