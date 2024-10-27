/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:36:48 by malia             #+#    #+#             */
/*   Updated: 2024/03/08 16:02:31 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compte la longueur d'un nombre sans compter le - ou + devant

int	ft_lenint(long long n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	while (n < -9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
