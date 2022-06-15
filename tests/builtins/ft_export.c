/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:36:25 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/15 19:50:09 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_export(char **env)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	while (env[i])
	{
		j = 0;
		n = 0;
		while (env[i][j])
		{
			ft_putchar_fd(env[i][j], 1);
			if (env[i][j] == '=' && n == 0)
			{
				ft_putchar_fd('\"', 1);
				n++;
			}
			if (!env[i][j + 1] && n != 0)
				ft_putchar_fd('\"', 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	ft_export(char **env)
{
	print_export(env);
}
