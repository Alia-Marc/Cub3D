/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:00:40 by marc              #+#    #+#             */
/*   Updated: 2025/04/17 17:44:26 by malia            ###   ########.fr       */
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

// void	print_map_v2(char **map)
// {
// 	int x = 0;
// 	int y = 0;
// 	while (map[x])
// 	{
// 		ft_printf("{");
// 		y = 0;
// 		while (map[x][y])
// 		{
// 			ft_printf("%c", map[x][y]);
// 			y++;
// 			if (map[x][y])
// 				ft_printf(", ");
// 		}
// 		ft_printf("}\n");
// 		x++;
// 	}
// }

int	main(int ac, char **av)
{
	t_map	map;

	if (ac == 2 && ft_strncmp(".cub", &av[1][ft_strlen(av[1]) - 4], 4) == 0)
	{
		if (check_and_open_map(av[1], &map))
		{
			if (parse_map(&map))
				init_and_launch(&map);
			else
				return (free_map(&map), 1);
		}
	}
	else
		return (ft_fdprintf(2, "Error\nInvalid arguments\n"), 1);
	return (0);
}
