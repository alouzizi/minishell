/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:38:34 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/15 16:44:23 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	shlvl_handling(char **env, int i)
{
	char	*tmp;
	char	*s;
	int		t;

	tmp = ft_strdup("SHLVL=");
	s = ft_strrchr(env[i], '=');
	++s;
	t = ft_atoi(s) + 1;
	if (t < 0)
		t = 0;
	s = ft_itoa(t);
	env[i] = ft_strjoin(tmp, s);
	free(s);
	free(tmp);
}

void	ft_update_env(char **env)
{
	int	i;
	int	k;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp("SHLVL=", env[i], ft_strlen("SHLVL=")))
		{
			k = 1;
			shlvl_handling(env, i);
		}
		else
			env[i] = ft_strdup(env[i]);
	}
	if (k != 1)
	{
		env[i] = ft_strdup("SHLVL=1");
		i++;
	}
	env[i] = NULL;
}

void	ft_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		printf("%s\n", env[i]);
}
