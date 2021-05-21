/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:07:34 by avilla-m          #+#    #+#             */
/*   Updated: 2021/05/20 15:50:30 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *s;
	int i;
	int j;

	if (!s1 || !s2)
		return (NULL);
	if (!(s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}

char	*ft_substr(char *s, int start, int end)
{
	char *str;
	int i;

	if (start < 0 || end < 0 || (end - start) < 0 || !s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	i = 0;
	while (s[start + i] && (start + i) <= end)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_newline(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int get_next_line(char **line)
{
	char		buf[250];
	char		*tmp;
	static char	*s;
	int			n;

	if (!line || (n = read(0, buf, 0)) < 0)
		return (-1);
	if (!s)
	{
		s = (char *)malloc(sizeof(char));
		if (!s)
			return (-1);
		*s = '\0';
	}
	tmp = 0;
	if (ft_newline(s) == -1)
	{
		while ((n = read(0, buf, 249)) > 0)
		{
			buf[n] = '\0';
			tmp = ft_strjoin(s, buf);
			free(s);
			s = tmp;
			if (ft_newline >= 0)
				break;
		}
	}
	if (ft_newline(s) >= 0)
	{
		*line = ft_substr(s, 0, ft_newline(s));
		tmp = ft_substr(s, ft_newline(s) + 1, ft_strlen(s) - 1);
		free(s);
		s = tmp;
		return (1);
	}
	if (ft_newline(s) == -1)
	{
		*line = ft_substr(s, 0, ft_strlen(s) - 1);
		free(s);
		s = 0;
		return (0);
	}
	return (-1);
}
