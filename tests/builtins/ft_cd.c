/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:52:24 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/17 23:01:38 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_cd(char **cmd, char **env)
{
	if (!cmd[1])
	{
		if (chdir(getenv("HOME")))
			perror("minishell : cd:");
	}
	else
	{
		if (chdir(cmd[1]))
			perror("minishell : cd ");
	}
}
