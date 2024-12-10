/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:04:01 by emilefourni       #+#    #+#             */
/*   Updated: 2024/12/10 13:30:53 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	check_char_map(char **map, t_map *pos_player)
{
	int (row) = 0;
	int (seen) = 0;
	int col;

	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (IS_INVALID_CHAR(map[row][col]))
				return(ft_printf("Error\n"BAD_CHAR_MAP), 0);
			if (IS_POSITION_PLAYER(map[row][col]))
			{
				pos_player->start_y = row;
				pos_player->start_x = col;
				seen++;
			}
			col++;
		}
		row++;
	}
	pos_player->nb_rows = row;
	if (seen != 1)
	    return (ft_printf("Error\n"WRONG_PLAYER_POS), 0);
	return (1);
}

int	is_surrounded_by_walls(char **map, int row, int col, int rows)
{
	int (current_row_length) = ft_strlen(map[row]);

	if (row == 0 || col >= current_row_length || map[row - 1][col] == ' ')
		return ( 0);
	if (row == rows - 1 || col >= ft_strlen(map[row + 1]) || map[row + 1][col] == ' ')
		return (0);
	if (col == 0 || map[row][col - 1] == ' ')
		return (0);
	if (col == ft_strlen(map[row]) - 1 || map[row][col + 1] == ' ')
		return (0);
	return (1);
}

int validate_edge_row(char *row, int index_row, t_map *map)
{
	int	(i) = 0;
	int (len_row) = ft_strlen(row);
	int (len_next_row) = ft_strlen(map->map[1]);

	if (index_row == 0 && map->map[index_row + 1][len_row] != '1' && len_row < len_next_row)
			return (0);
	while (row[i])
	{
		if (row[i] != '1' && row[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	validate_map_interior(char **map, int rows)
{
	int (row) = 1;
	int	(len_row) = 0;

	while (row < rows - 1)
	{
		int col = 0;
		while (map[row][col])
		{
			len_row = ft_strlen(map[row]);
			if (IS_CELL_SUURROUNDED(map[row][col]))
			{
				if (!is_surrounded_by_walls(map, row, col, rows))
					return (0);
				if (map[row + 1][len_row] != '1' && len_row < ft_strlen(map[row + 1]))
					return (0);
			}
			col++;
		}
		row++;
	}
	return (1);
}

int parse_map(t_map *map)
{
	if (!check_char_map(map->map, map))
		return (0);
	if (!validate_edge_row(map->map[0], 0, map))
		return (ft_printf("Error\n"MAP_IS_INVALID), 0);
	if (!validate_edge_row(map->map[map->nb_rows - 1], 1, map))
		return (ft_printf("Error\n"MAP_IS_INVALID), 0);
	if (!validate_map_interior(map->map, map->nb_rows))
		return (ft_printf("Error\n"MAP_IS_INVALID), 0);
	return (1);
}


