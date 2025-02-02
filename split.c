/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:54:44 by slebik            #+#    #+#             */
/*   Updated: 2025/01/21 12:54:44 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_word(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

char	*alloc_word_memory(char const *s, char sep)
{
	int		i;
	int		len;
	char	*tab;

	len = 0;
	i = 0;
	while (s[len] != sep && s[len])
		len++;
	tab = malloc(sizeof(char) * (len + 1));
	if (tab == NULL)
		return (NULL);
	while (i < len)
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	int			j;
	int			nbr_of_words;
	char		**tab;

	i = 0;
	j = 0;
	nbr_of_words = count_word(s, c);
	tab = malloc(sizeof(char *) * (nbr_of_words + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			tab[j] = alloc_word_memory(&s[i], c);
			j++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

void	ft_free_split(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}