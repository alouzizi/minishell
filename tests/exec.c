/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:14:09 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/15 12:10:53 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_path(char *s, char **env)
{
	int		i;
	char	**paths;

	paths = ft_split(getenv("PATH"), ':');
	i = -1;
	while (paths[++i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		paths[i] = ft_strjoin(paths[i], s);
	}
	return (paths);
}

int	builtincmp(char *s1, char *s2)
{
	int	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

int	isbuiltin(char **cmd, char **env)
{
	if (!cmd[0])
		return (1);
	if (!builtincmp(cmd[0], "pwd"))
		return (ft_pwd(), 1);
	else if (!builtincmp(cmd[0], "echo"))
		return (ft_echo(cmd), 1);
	else if (!builtincmp(cmd[0], "env"))
		return (ft_env(env), 1);
	else if (!builtincmp(cmd[0], "export"))
		return (1);
	else if (!builtincmp(cmd[0], "unset"))
		return (1);
	else if (!builtincmp(cmd[0], "cd"))
		return (1);
	else if (!builtincmp(cmd[0], "exit"))
		return (1);
	else
		return (0);
}

void	commands_execution(char **path, char **cmd, char **env)
{
	int	fd;
	int	i;

	if (!access(cmd[0], X_OK))
		path[i] = cmd[0];
	else
	{
		i = -1;
		while (path[++i])
			if (!access(path[i], X_OK))
				break ;
	}
	fd = fork();
	if (!fd)
	{
		execve(path[i], cmd, env);
		exit (0);
	}
	else
	{
		g_global.l = 1;
		waitpid(fd, NULL, 0);
	}
}

void	execute(char *s, char **env)
{
	char	**path;
	char	**cmd;

	cmd = ft_split(s, ' ');
	if (!isbuiltin(cmd, env))
	{
		path = get_path(cmd[0], env);
		commands_execution(path, cmd, env);
	}
}
