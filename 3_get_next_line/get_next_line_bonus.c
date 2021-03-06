/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:37:47 by avilla-m          #+#    #+#             */
/*   Updated: 2021/05/11 12:28:40 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!s || ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == 0)
		return (0);
	if (start < 0)
		return (ft_strdup(""));
	ft_strlcpy(new, s + start, len + 1);
	return (new);
}

int	ft_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_read(int fd, int *n, char *buff, char **s)
{
	char	*tmp;

	tmp = 0;
	*n = read(fd, buff, BUFFER_SIZE);
	if (*n > 0)
	{
		buff[*n] = 0;
		tmp = ft_strjoin(*s, buff);
		if (!tmp)
			return (-1);
		free(*s);
		*s = tmp;
		if (ft_newline(*s) == -1)
			ft_read(fd, n, buff, s);
	}
	return (0);
}

int	ft_line_and_return(int n, char **s, char **line)
{
	char	*tmp;

	tmp = 0;
	if (n == 0 && (ft_newline(*s) == -1))
	{
		*line = ft_substr(*s, 0, ft_strlen(*s));
		free(*s);
		*s = NULL;
		return (0);
	}
	else if (n >= 0 && (ft_newline(*s) >= 0))
	{
		*line = ft_substr(*s, 0, ft_newline(*s));
		tmp = ft_substr(*s, ft_newline(*s) + 1, ft_strlen((*s)));
		free(*s);
		*s = tmp;
		return (1);
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	static char	*s[10];
	char		buff[BUFFER_SIZE + 1];
	int			n;

	if (BUFFER_SIZE <= 0 || !line || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (!s[fd])
	{
		s[fd] = ft_strdup("");
		if (!s[fd])
			return (-1);
	}
	n = 0;
	if (ft_newline(s[fd]) == -1)
	{	
		if (ft_read(fd, &n, buff, &s[fd]) == -1)
			return (-1);
	}
	return (ft_line_and_return(n, &s[fd], line));
}
