/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gramos-d <gramos-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:35:39 by gramos-d          #+#    #+#             */
/*   Updated: 2022/11/15 14:51:03 by gramos-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] != c)
		return (0);
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*line;
	size_t	i;
	size_t	y;

	if (s2[0] == 0)
		return (NULL);
	line = malloc(sizeof (char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	i = -1;
	y = -1;
	if (!line)
		return (0);
	while (s1 && s1[++i])
		line[++y] = s1[i];
	while (*s2 && *s2 != '\n')
		line[++y] = *s2++;
	if (*s2 == '\n')
		line[++y] = '\n';
	line[++y] = '\0';
	if (s1)
		free(s1);
	return (line);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i++] = 0;
	return (dst);
}

size_t	ft_strlen(const char *len)
{
	size_t	i;

	if (!len || len[0] == 0)
		return (0);
	i = 1;
	while (len[i] && len[i - 1] != '\n')
		i++;
	return (i);
}
