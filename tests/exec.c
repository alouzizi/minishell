/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:14:09 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/08 13:57:01 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	**get_path(char *s, char **env)
{
	int		i;
	char	*path;
	char	**paths;

	i = -1;
	while (env[++i])
		if (ft_strnstr(env[i], "PATH=", 5))
			break ;
	path = ft_strnstr(env[i], "PATH=", 5);
	paths = ft_split(path, ':');
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
	path = getenv("PATH");
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
		exit(0);
	}
	else
		waitpid(fd, NULL, 0);
}
