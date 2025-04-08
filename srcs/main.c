/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:00:40 by marc              #+#    #+#             */
/*   Updated: 2025/04/08 16:55:22 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// void	print_map(char **map)
// {
// 	int	i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		printf("%s\n", map[i]);
// 		i++;
// 	}
// }

void	print_map_v2(char **map)
{
	int x = 0;
	int y = 0;
	while (map[x])
	{
		ft_printf("{");
		y = 0;
		while (map[x][y])
		{
			ft_printf("%c", map[x][y]);
			y++;
			if (map[x][y])
				ft_printf(", ");
		}
		ft_printf("}\n");
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2 && ft_strncmp(".cub", &argv[1][ft_strlen(argv[1]) - 4], 4) == 0)
	{
		if (check_and_open_map(argv[1], &map))
		{
			if (parse_map(&map))
				init_and_launch(&map);
			//print_map_v2(map.map);
			free_map(&map);
		}
	}
	else
		ft_printf("Error\nInvalid arguments\n");
	return (0);
}
