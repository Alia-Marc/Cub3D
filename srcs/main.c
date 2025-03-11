/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:00:40 by marc              #+#    #+#             */
/*   Updated: 2025/01/29 19:09:17 by emfourni         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2 && ft_strncmp(".cub", &argv[1][ft_strlen(argv[1]) - 4], 4) == 0)
	{
		if (check_and_open_map(argv[1], &map))
		{
			if (parse_map(&map))
				manage_window(&map);
			free_map(&map);
		}
	}
	else
		ft_printf("Error\nInvalid arguments\n");
	return (0);
}
