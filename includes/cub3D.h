/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:59:29 by marc              #+#    #+#             */
/*   Updated: 2024/11/29 16:50:45 by emilefourni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# pragma once
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
    char    **map;
	char    *north_texture_path;
    char    *south_texture_path;
    char    *west_texture_path;
    char    *east_texture_path;
    int		floor_red;
	int		floor_green;
	int		floor_blue;
	int		ceiling_red;
	int		ceiling_green;
	int		ceiling_blue;
	int		start_y;
	int		start_x;
	int		nb_rows;
}   t_map;

///////////////////////////////////////MAP_PARSING//////////////////////////////

//map_creation.c

#define BAD_FILE_NAME "tia du caca dans le nom de la map, ca foit finir par .cub\n"
#define BAD_OPENING "ca a chie dans la colle a l'ouverture du fichier le S\n"
#define ERROR_WALL_TEXTURE_PATH "tia une couille dans le texture path des wall zebi\n"
#define ERROR_VALUE_RGB "tia des valeurs RGB invalides le S\n"
#define OUT_OF_RANGE(x) ((x) < 0 || (x) > 255)
#define IS_NUM(c) ((c) >= '0' && c <= '9')

int check_and_open_map(char *file_name, t_map *map);

//map_creation_utils.c

char	*path_texture_cpy(char *s, int i);
char	**free_line_map(char **map);
int 	check_rgb(char **rgb_values);

//parse_map.c

#define BAD_CHAR_MAP "tia un char qu'a rien a foutre dans la map zebi\n"
#define IS_INVALID_CHAR(c) ((c) != '1' && (c) != '0' && (c) != 'N' && (c) != 'E' && (c) != 'S' && (c) != 'W' && (c) != ' ')
#define IS_POSITION_PLAYER(c) ((c) == 'N' || (c) == 'S' || (c) == 'E' || (c) == 'W')
#define IS_CELL_SUURROUNDED(c) ((c) == 'N' || (c) == 'S' || (c) == 'E' || (c) == 'W' || (c) == '0')
#define WRONG_PLAYER_POS "tia un truc nique avec ta position du player zebi\n"
#define MAP_IS_INVALID "elle est naze ta carte on dirait du gruyere zebi\n"

int		parse_map(t_map *map);

#endif