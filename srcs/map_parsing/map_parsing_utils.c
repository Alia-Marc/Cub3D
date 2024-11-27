/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:05:04 by emilefourni       #+#    #+#             */
/*   Updated: 2024/11/27 11:43:16 by emilefourni      ###   ########.fr       */
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
	if (s[i])
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

void	fill_ceiling_rgb(char *res, int index, t_map *map)
{
	char	*temp;
	char	**int_tab;
	
	temp = path_texture_cpy(res, index);
	int_tab = ft_split(temp, ',');
	map->ceiling_red = ft_atoi(int_tab[0]);
	map->ceiling_green = ft_atoi(int_tab[1]);
	map->ceiling_blue = ft_atoi(int_tab[2]);
	free(temp);
	ft_free_tab(int_tab);		
}

void	fill_floor_rgb(char *res, int index, t_map *map)
{
	char	*temp;
	char	**int_tab;

	temp = path_texture_cpy(res, index);
	int_tab = ft_split(temp, ',');
	map->floor_red = ft_atoi(int_tab[0]);
	map->floor_green= ft_atoi(int_tab[1]);
	map->floor_blue = ft_atoi(int_tab[2]);
	free(temp);
	ft_free_tab(int_tab);
}

t_map	*fill_struct(char *res, t_map *map)
{
	int	index;

	index = 0;
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
	if (!map->north_texture_path || !map->south_texture_path || !map->east_texture_path || !map->west_texture_path)
		return (ft_printf(ERROR_WALL_TEXTURE_PATH), NULL);
	if (OUT_OF_RANGE(map->ceiling_red) || OUT_OF_RANGE(map->ceiling_green) || OUT_OF_RANGE(map->ceiling_blue) ||
   		 OUT_OF_RANGE(map->floor_red) || OUT_OF_RANGE(map->floor_green) || OUT_OF_RANGE(map->floor_blue)) 
		return (ft_printf(ERROR_VALUE_RGB), NULL);
	return (map);
}

int	check_and_open_map(char *file_name, t_map *map)
{
    int		fd;
	char	*res;
	char	*line;
    
	if (ft_strncmp(".cub", &file_name[ft_strlen(file_name) - 4], 4) != 0)
        return (ft_printf(BAD_FILE_NAME), 0);
    fd = open(file_name, O_RDONLY);
    if (fd < 1)
        return (ft_printf(BAD_OPENING), close(fd), 0);
	res = get_next_line(fd);
	while (res)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		res = ft_strjoin(res, line);
		free(line);
	}
	map = fill_struct(res, map);
	if (map)
    	map->map = ft_split(res, '\n');
    return (close(fd), free(res), 1);
}