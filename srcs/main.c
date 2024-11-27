/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:00:40 by marc              #+#    #+#             */
/*   Updated: 2024/11/27 11:54:05 by emilefourni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	print_map(char **map)
{
	int	i = 0;
	int	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map *map;

	if (argc == 2)
	{
		if (check_and_open_map(argv[1], map))
			map->map = parse_map(argv[1]);
		else
			return (1);
	}
	return (0);
}
