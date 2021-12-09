/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 12:38:21 by avilla-m          #+#    #+#             */
/*   Updated: 2021/05/06 12:38:23 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (*s++)
		n++;
	return (n);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 == 0 || !s1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (src[i] != 0)
	{
		if (i + 1 < size)
			dst[i] = src[i];
		if (i + 1 == size)
			dst[i] = 0;
		i++;
	}
	if (i + 1 <= size)
		dst[i] = 0;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(sizeof(char) * len);
	if (!new)
		return (0);
	ft_strlcpy(new, s1, len);
	ft_strlcat(new, s2, len);
	return (new);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dst_len;
	size_t		src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size > 0 && dst_len < (size - 1))
	{
		i = 0;
		while (src[i] && (dst_len + i) < (size - 1))
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = 0;
	}
	if (dst_len > size)
		dst_len = size;
	return (dst_len + src_len);
}
