/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:40:20 by emilefourni       #+#    #+#             */
/*   Updated: 2025/04/17 19:42:33 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	skip_char_then_spaces(char *s, int *i)
{
	while (s[*i] != ' ')
		(*i)++;
	while (s[*i] == ' ')
		(*i)++;
	return (*i);
}

char	*path_texture_cpy(char *s, int i)
{
	char	*dup;
	int		temp;

	int (len) = 0;
	temp = skip_char_then_spaces(s, &i);
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
	if (!map->north_texture_path || !map->south_texture_path
		|| !map->west_texture_path || !map->east_texture_path)
		return (ft_fdprintf(2, "Error\ntia une couille")
			, ft_fdprintf(2, " dans le texture path des wall zebi\n")
			, free_map(map), 0);
	if ((out_of_range(map->ceiling_red) || out_of_range(map->ceiling_green)
			|| out_of_range(map->ceiling_blue) || out_of_range(map->floor_red)
			|| out_of_range(map->floor_green) || out_of_range(map->floor_blue)))
		return (ft_fdprintf(2, "Error\nvaleurs RGB OUT_OF_RANGE ou")
			, ft_fdprintf(2, " tia pas bien rempli les valeurs le S\n")
			, free_map(map), 0);
	return (1);
}

char	**free_line_map(char **map)
{
	int (free_line) = 0;
	int (shift_index) = 0;
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
			if (!((rgb_values[i][j] >= '0' && rgb_values[i][j] <= '9')
				|| rgb_values[i][j] == ' '))
				return (0);
			j++;
		}
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}
