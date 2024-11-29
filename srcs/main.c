/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilefournier <emilefournier@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:00:40 by marc              #+#    #+#             */
/*   Updated: 2024/11/29 15:37:53 by emilefourni      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	main(int argc, char **argv)
{
	t_map map;

	if (argc == 2)
	{
		if (check_and_open_map(argv[1], &map))
		{
			if (parse_map(&map))
				ft_printf("map is valid\n");
			else 
				ft_printf("map is invalid\n");
		}
		else
			return (0);
	}
	return (0);
}
