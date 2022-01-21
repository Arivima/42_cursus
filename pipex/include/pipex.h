/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:53:28 by avilla-m          #+#    #+#             */
/*   Updated: 2022/01/19 14:53:37 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// includes
# include "libft.h"
# include "ft_printf.h"
# include <unistd.h> // fork, pipe, dup2
# include <stdio.h> // perror
# include <stdlib.h> // exit
# include <fcntl.h> // open
# include <sys/wait.h> // waitpid
// defines
# define FILE1 1
# define CMD1 2
# define CMD2 3
# define FILE2 4
# define FAILURE_ERROR_MSG "ft_error failure"
# define FAILURE_INPUT 1
# define FAILURE_INPUT_MSG "Bad input, please retry with the following \
format => ./pipex file1 \"cmd1\" \"cmd2\" file2"
# define FAILURE_OPEN_INFILE 2
# define FAILURE_OPEN_INFILE_MSG "Failed to open specified file1 - open()"
# define FAILURE_OPEN_OUTFILE 3
# define FAILURE_OPEN_OUTFILE_MSG "Failed to open specified file2 - open()"
# define FAILURE_PIPE 4
# define FAILURE_PIPE_MSG "Failed to create a pipe - pipe()"
# define FAILURE_FORK 5
# define FAILURE_FORK_MSG "Failed to create child process - fork()"
# define FAILURE_PARSING 6
# define FAILURE_PARSING_MSG "Parsing failure - ft_split() | ft_strjoin()"
# define FAILURE_EXECVE 7
# define FAILURE_EXECVE_MSG "Execve failure - command not found"
# define FAILURE_DUP 8
# define FAILURE_DUP_MSG "Swap fd failure - dup2()"

// prototypes
void	fork_process(char **av, char **env, int command);
void	child_process(char **av, char **env, int command);
char	**build_full_path(char **env, char **cmd);
char	**parse_path(char **env);
void	execute_cmd(char **path, char **cmd, char **env);
void	swap_fd(int swap_a1, int swap_a2, int swap_b1, int swap_b2);
int		ft_error(int error);

#endif
