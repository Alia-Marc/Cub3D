/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alia <alia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:05:04 by emilefourni       #+#    #+#             */
/*   Updated: 2025/03/14 10:32:58 by alia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	fill_ceiling_rgb(char *res, int index, t_map *map)
{
	char	*temp;
	char	**int_tab;

	temp = path_texture_cpy(res, index);
	int_tab = ft_split(temp, ',');
	if (!check_rgb(int_tab))
	{
		free(temp);
		ft_free_tab(int_tab);
		return ;
	}
	map->ceiling_red = ft_atoi(int_tab[0]);
	map->ceiling_green = ft_atoi(int_tab[1]);
	map->ceiling_blue = ft_atoi(int_tab[2]);
	free(temp);
	ft_free_tab(int_tab);
}

static void	fill_floor_rgb(char *res, int index, t_map *map)
{
	char	*temp;
	char	**int_tab;

	temp = path_texture_cpy(res, index);
	int_tab = ft_split(temp, ',');
	if (!check_rgb(int_tab))
	{
		free(temp);
		ft_free_tab(int_tab);
		return ;
	}
	map->floor_red = ft_atoi(int_tab[0]);
	map->floor_green = ft_atoi(int_tab[1]);
	map->floor_blue = ft_atoi(int_tab[2]);
	free(temp);
	ft_free_tab(int_tab);
}

static t_map	*fill_struct(char *res, t_map *map)
{
	int	(index) = 0;

	while (res[index])
	{
		if (res[index] == 'N' && (res[index + 1] == 'O' && res[index + 1]))
			map->north_texture_path = path_texture_cpy(res, index);
		else if (res[index] == 'S' && (res[index + 1] == 'O' && res[index + 1]))
			map->south_texture_path = path_texture_cpy(res, index);
		else if (res[index] == 'W' && (res[index + 1] == 'E' && res[index + 1]))
			map->west_texture_path = path_texture_cpy(res, index);
		else if (res[index] == 'E' && (res[index + 1] == 'A' && res[index + 1]))
			map->east_texture_path = path_texture_cpy(res, index);
		else if (res[index] == 'F' && (res[index + 1] == ' ' && res[index + 1]))
			fill_floor_rgb(res, index, map);
		else if (res[index] == 'C' && (res[index + 1] == ' ' && res[index + 1]))
			fill_ceiling_rgb(res, index, map);
		index++;
	}
	if (!check_struct_fill(map))
		return (NULL);
	return (map);
}

int	check_and_open_map(char *file_name, t_map *map)
{
	int		fd;
	char	*res;
	char	*line;
	char	*temp;

	fd = open(file_name, O_RDONLY);
	if (fd < 1)
		return (ft_printf("Error\n"BAD_OPENING), 0);
	res = get_next_line(fd);
	if (!res)
	 	return (ft_printf("Error\nEmpty map\n"), close(fd), 0);
	while (res)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = res;
		res = ft_strjoin(res, line);
		free(temp);
		free(line);
	}
	if (res)
		free(line);
	init_map(map);
	map = fill_struct(res, map);
	if (!map)
		return (close(fd), free(res), 0);
	map->map = ft_split(res, '\n');
	map->map = free_line_map(map->map);
	return (close(fd), free(res), 1);
}
