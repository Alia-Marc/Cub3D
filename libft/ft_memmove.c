/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:57:54 by malia             #+#    #+#             */
/*   Updated: 2023/11/10 17:07:38 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dcast;
	unsigned char	*scast;

	dcast = (unsigned char *)dest;
	scast = (unsigned char *)src;
	if (!dcast && !scast)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			dcast[n - 1] = scast[n - 1];
			n--;
		}
	}
	return (dest);
}
