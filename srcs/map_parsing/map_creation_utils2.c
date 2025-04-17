/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:44:20 by emfourni          #+#    #+#             */
/*   Updated: 2025/04/17 16:07:53 by malia            ###   ########.fr       */
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
	map->ceiling_red = -1;
	map->ceiling_green = -1;
	map->ceiling_blue = -1;
	map->floor_red = -1;
	map->floor_green = -1;
	map->floor_blue = -1;
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
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
