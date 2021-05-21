/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:29:40 by avilla-m          #+#    #+#             */
/*   Updated: 2021/05/18 17:44:31 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
	char	used[127];

	if (ac == 3)
	{
		i = 0;
		while (used[i])
			used[i++] = 0;
		i = 0;
		while (av[2][i])
			used[(unsigned char) av[2][i++]] = 1;
		i = 0;
		while (av[1][i])
		{
			if (used[(unsigned char) av[1][i]])
			{
				write(1, &av[1][i], 1);
				used[(unsigned char) av[1][i]] = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
