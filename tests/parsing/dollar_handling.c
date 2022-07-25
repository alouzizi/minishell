/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 02:52:01 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/24 22:43:31 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_env(char *str, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(str, env[i], ft_strlen(str)))
			return (&env[i][ft_strlen(str)]);
	}
	return (NULL);
}

char	*between_dollars(char *s, int *j)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '$' && ft_isalnum(s[i]))
		i++;
	str = malloc(sizeof(char) * i + 1);
	i = 0;
	while (s[i] && s[i] != '$' && ft_isalnum(s[i]))
	{
		str[i] = s[i];
		i++;
	}
	*j += i;
	str[i] = '\0';
	str = ft_strjoin(str, "=");
	return (str);
}

char	*between_dollars2(char *s, int *j)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != '$')
		i++;
	str = malloc(sizeof(char) * i + 1);
	i = 0;
	while (s[i] && s[i] != '$')
	{
		str[i] = s[i];
		i++;
	}
	*j += i - 1;
	str[i] = '\0';
	return (str);
}

char	*get_value(char *str, char **env)
{
	int		i;
	char	*s;

	i = -1;
	s = NULL;
	while (str[++i])
	{
		if (str[i] == '$' && ft_isalnum(str[i + 1]))
			s = ft_strjoin(s, get_env(between_dollars(&str[i + 1], &i), env));
		else if (str[i] == '$' && str[i + 1] == '?')
		{
			s = ft_strjoin(s, ft_itoa(g_global.status));
			i++;
		}
		else
		{
			if (str[i] == '$')
			{
				s = ft_strjoin(s, "$");
				i++;
			}
			s = ft_strjoin(s, between_dollars2(&str[i], &i));
		}
	}
	return (s);
}

void	expand_dollar_value(char **s, int *tab, char **env)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i][0] == '<')
			i++;
		else if (ft_strchr(s[i], '$') && !tab[i])
			s[i] = get_value(s[i], env);
		i++;
	}
}
