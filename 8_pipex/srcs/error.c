/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:02:35 by avilla-m          #+#    #+#             */
/*   Updated: 2022/01/19 15:02:37 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(int error)
{
	if (error == FAILURE_INPUT)
		perror(FAILURE_INPUT_MSG);
	else if (error == FAILURE_OPEN_INFILE)
		perror(FAILURE_OPEN_INFILE_MSG);
	else if (error == FAILURE_OPEN_OUTFILE)
		perror(FAILURE_OPEN_OUTFILE_MSG);
	else if (error == FAILURE_PIPE)
		perror(FAILURE_PIPE_MSG);
	else if (error == FAILURE_FORK)
		perror(FAILURE_FORK_MSG);
	else if (error == FAILURE_PARSING)
		perror(FAILURE_PARSING_MSG);
	else if (error == FAILURE_DUP)
		perror(FAILURE_DUP_MSG);
	else
		perror(FAILURE_ERROR_MSG);
	exit(EXIT_FAILURE);
}
