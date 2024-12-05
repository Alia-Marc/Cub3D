/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emfourni <emfourni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:00:40 by marc              #+#    #+#             */
/*   Updated: 2024/12/05 14:56:29 by emfourni         ###   ########.fr       */
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
			argc*=1;
	}
	free_map(&map);
	return (0);
}
