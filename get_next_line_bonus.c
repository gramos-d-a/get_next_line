/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramos-d <gramos-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:31:24 by gramos-d          #+#    #+#             */
/*   Updated: 2022/11/15 16:15:39 by gramos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_read(char *next, int fd)
{
	int	len;

	ft_strcpy(next, &next[ft_strlen(next)], BUFFER_SIZE);
	len = read(fd, next, BUFFER_SIZE);
	return (len);
}

char	*get_next_line(int fd)
{
	static char	next[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			len;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > FOPEN_MAX)
		return (0);
	line = ft_strjoin(0, next[fd]);
	if (!(ft_strchr(next[fd], '\n')))
	{
		len = ft_read(next[fd], fd);
		if (len < 0)
		{
			free (line);
			return (NULL);
		}
		while (len > 0)
		{
			line = ft_strjoin(line, next[fd]);
			if (ft_strchr(next[fd], '\n'))
				break ;
			len = ft_read(next[fd], fd);
		}
	}
	ft_strcpy(next[fd], &next[fd][ft_strlen(next[fd])], BUFFER_SIZE);
	return (line);
}
