/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:38:34 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/15 11:29:53 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

char	**ft_arr_copy(char **arr)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * arr_len(arr) + 1);
	while (arr[i])
	{
		copy[i] = ft_strdup(arr[i]);
		i++;
	}
	copy[i + 1] = 0;
	return (copy);
}

void	ft_env(char **env)
{
	char	**copy;
	int		i;

	copy = ft_arr_copy(env);
	i = 0;
	while (copy[i++])
		ft_putendl_fd(copy[i], 1);
}
