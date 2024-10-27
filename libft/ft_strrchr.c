/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:00:02 by malia             #+#    #+#             */
/*   Updated: 2023/11/07 18:57:54 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	buff;
	int	check;

	i = 0;
	buff = 0;
	check = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			buff = i;
			check = 1;
		}
		i++;
	}
	if (check)
		return ((char *)s + buff);
	if (c == 0)
		return ((char *)s + i);
	return (0);
}
