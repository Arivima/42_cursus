/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:07:40 by avilla-m          #+#    #+#             */
/*   Updated: 2021/05/20 15:47:35 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	char *line;

    line = NULL;
	while (get_next_line(&line) > 0)
	{
		printf("line : %s", line);
		free(line);
		line = 0;
	}
	printf("endline : %s", line);
	free(line);
	line = 0;
}
