/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:45:45 by malia             #+#    #+#             */
/*   Updated: 2023/11/11 18:16:33 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*scast1;
	unsigned char	*scast2;

	i = 0;
	scast1 = (unsigned char *)s1;
	scast2 = (unsigned char *)s2;
	while (i < n)
	{
		if (scast1[i] - scast2[i] != 0)
			return (scast1[i] - scast2[i]);
		i++;
	}
	return (0);
}
