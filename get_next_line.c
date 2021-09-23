/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmendes- <cmendes-@students.42sp.org.br>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:56:42 by cmendes-          #+#    #+#             */
/*   Updated: 2021/09/09 16:56:42 by cmendes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line(int fd, char *s)
{
	static char		c[BUFFER_SIZE + 1];
	char			*aux;
	static int		i;
	ssize_t			j;

	ft_strlcpy(c, c + i, BUFFER_SIZE);
	s = ft_strjoin(s, c);
	while (!ft_strchr(c, '\n'))
	{
		j = read(fd, c, BUFFER_SIZE);
		if (j <= 0 && *s == '\0')
			return (free(s), NULL);
		c[j] = '\0';
		if (j == 0)
		{
			i = 0;
			return (read_line(s, '\n'));
		}
		aux = s;
		s = ft_strjoin(aux, c);
	}
	i = ft_strchr(c, '\n');
	return (read_line(s, '\n'));
}

char	*get_next_line(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (line(fd, NULL));
}
