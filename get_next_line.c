/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramos-d <gramos-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:31:24 by gramos-d          #+#    #+#             */
/*   Updated: 2022/11/15 15:59:55 by gramos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_read(char *next, int fd)
{
	int	len;

	ft_strcpy(next, &next[ft_strlen(next)], BUFFER_SIZE);
	len = read(fd, next, BUFFER_SIZE);
	return (len);
}

char	*get_next_line(int fd)
{
	static char	next[BUFFER_SIZE + 1];
	char		*line;
	int			len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	line = ft_strjoin(0, next);
	if (!(ft_strchr(next, '\n')))
	{
		len = ft_read(next, fd);
		if (len < 0)
		{
			free (line);
			return (NULL);
		}
		while (len > 0)
		{
			line = ft_strjoin(line, next);
			if (ft_strchr(next, '\n'))
				break ;
			len = ft_read(next, fd);
		}
	}
	ft_strcpy(next, &next[ft_strlen(next)], BUFFER_SIZE);
	return (line);
}
