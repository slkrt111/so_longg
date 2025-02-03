/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:31:04 by slebik            #+#    #+#             */
/*   Updated: 2025/02/03 11:47:36 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_to_buffer(int fd, char *buffer)
{
	int	bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes >= 0)
		buffer[bytes] = '\0';
	return (bytes);
}

char	*update_line(char *line, char *buffer)
{
	char	*new_line;

	new_line = ft_strjoin(line, buffer);
	if (new_line == NULL)
		free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;

	line = NULL;
	bytes = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (buffer[0] || bytes >= 0)
	{
		if (buffer[0] == '\0')
		{
			bytes = read_to_buffer(fd, buffer);
			if (bytes <= 0)
				break ;
		}
		line = update_line(line, buffer);
		if (!line)
			return (NULL);
		if (is_nl(buffer))
			break ;
	}
	return (line);
}
