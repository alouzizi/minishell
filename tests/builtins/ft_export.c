/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:36:25 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/18 00:54:00 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_export(char **copy)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	sort_array_alphabetically(copy);
	while (copy[++i])
	{
		j = 0;
		n = 0;
		ft_putstr_fd("declare -x ", 1);
		while (copy[i][j])
		{
			ft_putchar_fd(copy[i][j], 1);
			if (copy[i][j] == '=' && n == 0)
			{
				ft_putchar_fd('\"', 1);
				n++;
			}
			if (!copy[i][j + 1] && n != 0)
				ft_putchar_fd('\"', 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
	}
}

void	ft_export(char **cmd, char **env)
{
	char	**copy;

	if (!cmd[1])
	{
		copy = ft_arr_copy(env);
		print_export(copy);
	}
}