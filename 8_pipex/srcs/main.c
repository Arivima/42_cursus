/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:02:49 by avilla-m          #+#    #+#             */
/*   Updated: 2022/01/19 15:05:58 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int	infile;
	int	outfile;
	int	pipe_end[2];

	if (ac != 5)
		ft_error(FAILURE_INPUT);
	infile = open(av[FILE1], O_RDONLY);
	if (infile < 0)
		ft_error(FAILURE_OPEN_INFILE);
	outfile = open(av[FILE2], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (outfile < 0)
		ft_error(FAILURE_OPEN_OUTFILE);
	if (pipe(pipe_end) != 0)
		ft_error(FAILURE_PIPE);
	swap_fd(infile, STDIN_FILENO, pipe_end[1], STDOUT_FILENO);
	fork_process(av, env, CMD1);
	close(pipe_end[1]);
	swap_fd(outfile, STDOUT_FILENO, pipe_end[0], STDIN_FILENO);
	fork_process(av, env, CMD2);
	exit(EXIT_SUCCESS);
	return (0);
}

void	swap_fd(int swap_a1, int swap_a2, int swap_b1, int swap_b2)
{
	if (dup2(swap_a1, swap_a2) == -1)
		ft_error(FAILURE_PIPE);
	if (dup2(swap_b1, swap_b2) == -1)
		ft_error(FAILURE_PIPE);
}
