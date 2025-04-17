/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation_utils3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:26:44 by malia             #+#    #+#             */
/*   Updated: 2025/04/17 19:26:03 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	ft_strlen_until_non_numeric(char *str, int i)
{
	int	len;

	len = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		len++;
		i++;
	}
	return (len);
}

int	out_of_range(int x)
{
	return (x < 0 || x > 255);
}

int	is_char_invalid(char c)
{
	return (c != '1' && c != '0' && c != 'N'
		&& c != 'E' && c != 'S' && c != 'W' && c != ' ');
}

int	is_position_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_cell_suurrounded(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '0');
}
