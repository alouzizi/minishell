/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:33:00 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/25 04:55:19 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_minishell(char **cmd, char **env)
{
	int		fd;

	fd = fork();
	if (!fd)
	{
		execve("minishell", cmd, env);
		exit (0);
	}
	else
	{
		g_global.signal = 1;
		waitpid(fd, NULL, 0);
	}
}
