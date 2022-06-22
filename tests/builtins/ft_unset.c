/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:07:12 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/22 08:05:43 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_from_env(char **cmd, char **env)
{
	int	i;
	int	j;

	i = -1;
	j = 1;
	while (env[++i] && cmd[j])
	{
		if (!ft_strncmp(env[i], cmd[j], ft_strlen(cmd[j])))
		{
			env[i] = ft_strdup("");
			j++;
		}
	}
}

void	ft_unset(char **cmd, char **env)
{
	if (!cmd[1])
		return ;
	else
		remove_from_env(cmd, env);
}
