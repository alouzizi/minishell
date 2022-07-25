/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:36:25 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/24 23:09:55 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_to_value(char *arg, char **env, int i, int ptr)
{
	int		index;
	char	*value;

	index = 0;
	while (arg[index] != '=')
		index++;
	value = ft_strchr(arg, '=') + 1;
	while (env[++i])
	{
		if (!ft_strncmp(arg, env[i], index - 1))
		{
			ptr = 1;
			env[i] = ft_strjoin(env[i], value);
		}
	}
	i = index - 2;
	if (arg[i] == '+')
		i--;
	if (!ptr)
	{
		arg = ft_strjoin(ft_substr(arg, 0, i + 1), \
			ft_strjoin(ft_strdup("="), value));
		add_var_to_env(arg, env);
	}
}

void	add_to_env(char *var, char **env)
{
	int	i;
	int	index;
	int	b;
	int	ptr;

	index = 0;
	while (var[index] != '=')
		index++;
	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(var, env[i], index))
		{
			b = 1;
			ptr = i;
		}
	}
	if (b)
		env[ptr] = ft_strdup(var);
	else
		add_var_to_env(var, env);
}

void	add_to_export(char **env, char **cmd)
{
	int	i;
	int	j;

	i = 0;
	while (cmd[++i])
	{
		j = 0;
		if (cmd[i][j] == '_' && cmd[i][j + 1] == '=')
			return ;
		if (!ft_isalpha(cmd[i][j]))
		{
			printf("minishell: export: %s: invalid option\n", cmd[i]);
			return ;
		}
		while (cmd[i][j] && cmd[i][j] != '=' && cmd[i][j] != '+')
		{
			j++;
			if (cmd[i][j] == '=')
				add_to_env(cmd[i], env);
			else if (cmd[i][j] == '+' && cmd[i][j + 1] == '=')
				add_to_value(cmd[i], env, -1, 0);
			else if (cmd[i][j] != '+' && cmd[i][j + 1] != '=')
				add_variable(cmd[i], env);
		}
	}
}

void	print_export(char **copy)
{
	int	i;
	int	j;
	int	n;

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

	copy = ft_arr_copy(env);
	if (!cmd[1])
		print_export(copy);
	else
		add_to_export(env, cmd);
}
