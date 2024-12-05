/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:44:20 by emfourni          #+#    #+#             */
/*   Updated: 2024/12/05 14:46:47 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_map(t_map *map)
{
	map->north_texture_path = NULL;
	map->south_texture_path = NULL;
	map->west_texture_path = NULL;
	map->east_texture_path = NULL;
	map->map = NULL;
	map->ceiling_red = map->ceiling_green = map->ceiling_blue = 0;
	map->floor_red = map->floor_green = map->floor_blue = 0;
}

void	free_map(t_map *map)
{
	if (!map)
		return;
	if (map->north_texture_path)
		free(map->north_texture_path);
	if (map->south_texture_path)
		free(map->south_texture_path);
	if (map->west_texture_path)
		free(map->west_texture_path);
	if (map->east_texture_path)
		free(map->east_texture_path);
	if (map->map)
		ft_free_tab(map->map);
}


