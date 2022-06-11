/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:14:09 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/11 04:01:10 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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

void	execute(char *s, char **env)
{
	char	**path;
	char	**cmd;
	int		i;
	int		fd;

	i = 0;
	cmd = ft_split(s, ' ');
	if (cmd[0][0] == '/' || cmd[0][0] == '.')
		path = cmd;
	else
		path = get_path(cmd[0], env);
	while (path[i])
	{
		if (!access(path[i], X_OK))
			break ;
		i++;
	}
	fd = fork();
	if (!fd)
	{
		execve(path[i], cmd, env);
		exit (0);
	}
	else
		waitpid(fd, NULL, 0);
}
