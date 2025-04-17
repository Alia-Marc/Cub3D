/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:56:27 by malia             #+#    #+#             */
/*   Updated: 2025/04/17 19:10:39 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../includes/cub3D.h"

int	ft_atoi(char *nptr)
{
	int	sign;
	int	i;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+'
		|| ft_strlen_until_non_numeric(nptr, i) >= 4)
		return (-1);
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		result = result * 10 + nptr[i] % 16;
		i++;
	}
	if (result != 0)
		return (sign * result);
	return (0);
}
/*
int main(int ac, char **av)
{
	(void)ac;
	printf("%d", ft_atoi(av[1]));
	printf("%d", atoi(av[1]));
}*/
