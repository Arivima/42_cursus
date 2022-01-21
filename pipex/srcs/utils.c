/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avilla-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:03:01 by avilla-m          #+#    #+#             */
/*   Updated: 2022/01/19 15:07:47 by avilla-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_process(char **av, char **env, int command)
{
	pid_t	pid;
	int		status;

	pid = fork();
	waitpid(pid, &status, 0);
	if (pid == -1)
		ft_error(FAILURE_FORK);
	else if (pid == 0)
		child_process(av, env, command);
}

void	child_process(char **av, char **env, int command)
{
	char	**cmd;
	char	**path;

	cmd = ft_split(av[command], ' ');
	path = build_full_path(env, cmd);
	execute_cmd(path, cmd, env);
}

char	**build_full_path(char **env, char **cmd)
{
	char	**path;
	char	*tmp;
	int		i;

	path = parse_path(env);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
			ft_error(FAILURE_PARSING);
		free(path[i]);
		path[i] = 0;
		path[i] = ft_strjoin(tmp, cmd[0]);
		if (!path[i])
			ft_error(FAILURE_PARSING);
		free(tmp);
		tmp = 0;
		i++;
	}
	return (path);
}

char	**parse_path(char **env)
{
	int		i;
	char	**path;

	i = 0;
	while (env[i] && !ft_strnstr(env[i], "PATH=", 5))
		i++;
	path = ft_split(env[i] + 5, ':');
	return (path);
}

void	execute_cmd(char **path, char **cmd, char **env)
{
	int	i;

	i = 0;
	while (path[i])
	{
		execve(path[i], cmd, env);
		i++;
	}
	ft_error(FAILURE_EXECVE);
}
