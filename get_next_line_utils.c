/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:31:48 by slebik            #+#    #+#             */
/*   Updated: 2025/02/03 12:10:30 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	if (str[i] == '\n')
		return (i + 1);
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (s1 && s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		str[j++] = s2[i];
		if (s2[i++] == '\n')
			break ;
	}
	str[j] = '\0';
	free (s1);
	return (str);
}

int	is_nl(char *buffer)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (res == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			res = 1;
		buffer[i] = 0;
		i++;
	}
	return (res);
}
