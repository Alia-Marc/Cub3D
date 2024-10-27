/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malia <malia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:18:06 by malia             #+#    #+#             */
/*   Updated: 2024/01/23 09:10:22 by malia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	gnl_trim_line(char *stash, int stop)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(stash) + 1));
	if (!tmp)
		return ;
	while (stash[stop])
	{
		tmp[i] = stash[stop];
		i++;
		stop++;
	}
	tmp[i] = '\0';
	ft_bzero(stash, ft_strlen(stash));
	i = 0;
	while (tmp[i])
	{
		stash[i] = tmp[i];
		i++;
	}
	free(tmp);
	stash[i] = '\0';
}

char	*gnl_new_line(char *stash, int stop, char *buffer)
{
	int		i;
	char	*line;

	i = -1;
	line = (char *)malloc(sizeof(char) * (stop + 2));
	if (!line)
		return (NULL);
	while (++i <= stop)
		line[i] = stash[i];
	line[i] = '\0';
	gnl_trim_line(stash, stop + 1);
	free(buffer);
	return (line);
}

char	*gnl_ite(char *buffer, char *stash, int fd, int n_read)
{
	int	i;

	i = 0;
	while (n_read)
	{
		buffer[n_read] = '\0';
		ft_strcat(stash, buffer);
		while (stash[i])
		{
			if (stash[i] == '\n')
				return (gnl_new_line(stash, i, buffer));
			i++;
		}
		free(buffer);
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		n_read = read(fd, buffer, BUFFER_SIZE);
		if (n_read == -1)
			return (NULL);
	}
	if (ft_strlen(stash) != 0)
		return (gnl_new_line(stash, ft_strlen(stash), buffer));
	return (free(buffer), NULL);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE];
	char		*buffer;
	int			i;
	int			n_read;

	i = 0;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, &buffer, 0) == -1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (gnl_new_line(stash, i, buffer));
		i++;
	}
	n_read = read(fd, buffer, BUFFER_SIZE);
	if (n_read == -1)
		return (NULL);
	return (gnl_ite(buffer, stash, fd, n_read));
}
