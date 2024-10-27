/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:45:34 by malia             #+#    #+#             */
/*   Updated: 2023/11/09 14:43:59 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dcast;
	char	*scast;

	i = 0;
	dcast = (char *)dest;
	scast = (char *)src;
	if (!dcast && !scast)
		return (NULL);
	while (i < n)
	{
		dcast[i] = scast[i];
		i++;
	}
	return (dest);
}
