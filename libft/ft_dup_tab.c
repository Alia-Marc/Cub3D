/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marc <marc@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:38:03 by marc              #+#    #+#             */
/*   Updated: 2024/08/25 22:42:23 by marc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_dup_tab(char **tab)
{
	int		i;
	int		len_tab;
	char	**new_tab;

	i = 0;
	len_tab = ft_strlen2(tab);
	new_tab = (char **)malloc(sizeof(char *) * len_tab + 1);
	if (!new_tab)
		return (NULL);
	while (tab && tab[i])
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	return (new_tab);
}
