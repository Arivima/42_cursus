/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:44:40 by avilla-m          #+#    #+#             */
/*   Updated: 2021/05/18 17:54:42 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main (int ac, char **av)
{
	int		i, j;
	char	used[127];

	if (ac == 3)
	{
		i = 0;
		while (i < 127)
			used[i++] = 0;
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (av[i][j])
			{
				if (!used[(unsigned char) av[i][j]])
				{
					write(1, &av[i][j], 1);
					used[(unsigned char) av[i][j]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
