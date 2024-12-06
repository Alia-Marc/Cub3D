/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:00:40 by marc              #+#    #+#             */
/*   Updated: 2024/12/06 16:28:47 by emfourni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map map;

	if (argc == 2)
	{
		if (check_and_open_map(argv[1], &map))
		{
			if (parse_map(&map))
			{
				ft_printf("map is valid\n");
				print_map(map.map);
			}
			else
				ft_printf("map is invalid\n");
		}
		else
			argc*=1;
	}
	free_map(&map);
	return (0);
}



