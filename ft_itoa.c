/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slebik <slebik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:13:16 by slebik            #+#    #+#             */
/*   Updated: 2025/02/02 22:47:40 by slebik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	n_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*check_limit(int nb)
{
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	return (0);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = n_len(n);
	res = check_limit(n);
	if (res)
		return (res);
	res = malloc(sizeof (char) * (len + 1));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		n = -n;
	}
	while (n)
	{
		res[len - 1 - i] = (n % 10) + '0';
		n /= 10;
		i ++;
	}
	res[len] = '\0';
	return (res);
}

char	*ft_strdup(const char *str)
{
	int		size;
	int		i;
	char	*str1;
	char	*str2;

	i = 0;
	str2 = (char *)str;
	size = ft_strlen (str2);
	str1 = (char *) malloc ((size + 1) * sizeof(char));
	if (!str1)
		return (NULL);
	while (str2[i])
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
