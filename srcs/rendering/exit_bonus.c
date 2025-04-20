/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliam <aliam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:06:21 by malia             #+#    #+#             */
/*   Updated: 2025/04/20 01:54:39 by aliam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	exit_free_all(t_data *g, char *message, int exit_code)
{
	if (!exit_code)
		ft_printf("%s", message);
	else
		ft_fdprintf(2, "Error\n%s", message);
	free_all(g);
	exit(exit_code);
}

void	free_img(t_data *g, t_img *img)
{
	if (img->img)
	{
		mlx_destroy_image(g->mlx_ptr, img->img);
		img->img = NULL;
	}
}

void	free_all(t_data *g)
{
	free_map(g->map);
	free_img(g, &g->textures[0]);
	free_img(g, &g->textures[1]);
	free_img(g, &g->textures[2]);
	free_img(g, &g->textures[3]);
	free_img(g, &g->window);
	if (g->minimap_on != 0)
		free_img(g, &g->minimap);
	free_img(g, &g->sprites.campfire[0]);
	free_img(g, &g->sprites.campfire[1]);
	free_img(g, &g->sprites.campfire[2]);
	free_img(g, &g->sprites.campfire[3]);
	free_img(g, &g->door[0]);
	free_img(g, &g->door[1]);
	if (g->mlx_ptr && g->win_ptr)
		mlx_destroy_window(g->mlx_ptr, g->win_ptr);
	if (g->mlx_ptr)
	{
		mlx_destroy_display(g->mlx_ptr);
		free(g->mlx_ptr);
	}
}
