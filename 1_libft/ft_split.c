/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:33:23 by avilla-m          #+#    #+#             */
/*   Updated: 2021/03/12 14:59:24 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen_c(char const *s, int j, char c)
{
	int i;

	i = 0;
	while (s[j + i] != c && s[j + i])
		i++;
	return (i);
}

size_t		ft_flags(char const *s, char c)
{
	int i;
	int	flag;

	i = 0;
	while (*s)
	{
		flag = 0;
		while (*s != c && *s)
		{
			if (flag == 0)
			{
				flag = 1;
				i++;
			}
			s++;
		}
		if (flag == 0)
			s++;
	}
	return (i);
}

char		**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		**table;

	if (!s)
		return (0);
	if (!(table = (char**)malloc((sizeof(char *) * (ft_flags(s, c)) + 1))))
		return (0);
	table[ft_flags(s, c)] = 0;
	i = 0;
	k = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			k = ft_strlen_c(s, i, c);
			table[j++] = ft_substr(s, i, k);
			i += k;
		}
	}
	return (table);
}
