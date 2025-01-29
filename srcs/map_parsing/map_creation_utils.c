/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:40:20 by emilefourni       #+#    #+#             */
/*   Updated: 2024/12/06 15:03:33 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

char	*path_texture_cpy(char *s, int i)
{
	char	*dup;
	int		temp;
	int		(len) = 0;

	while (s[i] != ' ')
		i++;
	while (s[i] == ' ')
		i++;
	temp = i;
	while (s[i] && s[i] != '\n')
	{
		i++;
		len++;
	}
	if (len == 0)
		return (NULL);
	dup = (char *)malloc((len + 1) * sizeof(char));
	i = temp;
	temp = 0;
	if (dup == 0)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		dup[temp] = s[i];
		i++;
		temp++;
	}
	dup[temp] = '\0';
	return (dup);
}

int	check_struct_fill(t_map *map)
{
	if (!map->north_texture_path || !map->south_texture_path || !map->west_texture_path || !map->east_texture_path)
		return (ft_printf("Error\n"ERROR_WALL_TEXTURE_PATH), 0);
	if ((OUT_OF_RANGE(map->ceiling_red) || OUT_OF_RANGE(map->ceiling_green) || OUT_OF_RANGE(map->ceiling_blue) ||
		 OUT_OF_RANGE(map->floor_red) || OUT_OF_RANGE(map->floor_green) || OUT_OF_RANGE(map->floor_blue)))
		return (ft_printf("Error\n"ERROR_VALUE_RGB), 0);
	return (1);
}

char **free_line_map(char **map)
{
	int	(free_line) = 0;
	int	(shift_index) = 0;

	while (free_line < 6 && map[free_line]) 
	{
		free(map[free_line]);
		free_line++;
	}
	while (map[free_line])
		map[shift_index++] = map[free_line++];
	while (shift_index < free_line)
		map[shift_index++] = NULL;
	return (map);
}

int	check_rgb(char **rgb_values)
{
	int	i;
	int	j;

	i = 0;
	if (!rgb_values || !rgb_values[0] || !rgb_values[1] || !rgb_values[2])
		return (0);
	while (rgb_values[i])
	{
		j = 0;
		while (rgb_values[i][j])
		{
			if (!IS_NUM_OR_SPACE(rgb_values[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}
