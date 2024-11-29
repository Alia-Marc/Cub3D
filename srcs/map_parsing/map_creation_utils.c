/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:40:20 by emilefourni       #+#    #+#             */
/*   Updated: 2024/11/29 11:41:17 by emilefourni      ###   ########.fr       */
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

char **free_line_map(char **map)
{
    int	(free_line) = 0;
    int	(shift_index) = 0;

    while (free_line < 6 && map[free_line]) //the first six lines after the split are only the map info not the map itself
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