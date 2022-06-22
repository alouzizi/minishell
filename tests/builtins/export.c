/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:11:06 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/22 03:17:11 by ooumlil          ###   ########.fr       */
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
	copy = (char **)malloc(sizeof(char *) * arr_len(arr) + 1);
	while (arr[i])
	{
		copy[i] = ft_strdup(arr[i]);
		i++;
	}
	copy[i + 1] = 0;
	return (copy);
}

void	sort_array_alphabetically(char **arr)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_strcmp(arr[i], arr[j]) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	add_var_to_env(char *var, char **env)
{
	int	arr_size;

	arr_size = arr_len(env);
	env[arr_size] = ft_strdup(var);
	env[arr_size + 1] = NULL;
}

void	add_variable(char *arg, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (!ft_strcmp(arg, env[i]))
			return ;
	}
	add_var_to_env(arg, env);
}
