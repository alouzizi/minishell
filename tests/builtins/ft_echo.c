/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:40:19 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/15 00:13:36 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_n(char *cmd)
{
	int	i;

	if (!cmd)
		return (1);
	i = 0;
	if (cmd[i] == '-')
	{
		i++;
		while (cmd[i])
		{
			if (cmd[i] != 'n')
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

void	ft_echo(char **cmd)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	if (!cmd[1])
		return (ft_putstr_fd("\n", 1));
	while (cmd[i] && !check_n(cmd[i]))
	{
		if (cmd[i][1] != 'n')
			break ;
		k = 1;
		i++;
	}
	while (cmd[i])
	{
		ft_putstr_fd(cmd[i], 1);
		if (cmd[i + 1] && cmd[i][0])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!k)
		ft_putstr_fd("\n", 1);
}
