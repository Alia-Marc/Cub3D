/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:34:39 by malia             #+#    #+#             */
/*   Updated: 2023/11/09 14:01:29 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*scast;
	unsigned char	ccast;

	i = 0;
	scast = (unsigned char *)s;
	ccast = (unsigned char)c;
	while (i < n)
	{
		if (scast[i] == ccast)
			return (&scast[i]);
		i++;
	}
	return (NULL);
}
