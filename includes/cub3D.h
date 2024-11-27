/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:59:29 by marc              #+#    #+#             */
/*   Updated: 2024/11/27 11:42:33 by emilefourni      ###   ########.fr       */
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

#define BAD_FILE_NAME "tia du caca dans le nom de la map, ca foit finir par .cub\n"
#define BAD_OPENING "ca a chie dans la colle a l'ouverture du fichier le S\n"
#define ERROR_WALL_TEXTURE_PATH "tia une couille dans le texture path des wall zebi\n"
#define ERROR_VALUE_RGB "tia des valeurs RGB invalides le S\n"
#define OUT_OF_RANGE(x) ((x) < 0 || (x) > 255)

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
}   t_map;

//MAP_PARSING

int check_and_open_map(char *file_name, t_map *map);
void	print_map(char **map);


#endif