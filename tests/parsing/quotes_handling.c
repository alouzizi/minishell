/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:11:21 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/24 22:33:35 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	quotes_counting(char *s)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] && s[i] == '\'')
		{
			i++;
			count++;
			while (s[i] && s[i] != '\'')
				i++;
		}
		else if (s[i] && s[i] == '"')
		{
			i++;
			count++;
			while (s[i] && s[i] != '"')
				i++;
		}
		if (s[i] == '\'' || s[i] == '"')
			count++;
	}
	return (count % 2);
}

int	ft_skip(char *str, char c)
{
	int	i;

	i = 1;
	while (str[i] != c)
		i++;
	return (i);
}

int	ft_skip2(char *str, int *count, int *j)
{
	int	i;

	i = 0;
	(*j) = 1;
	if (str[i] == '<')
		while (str[i] == '<')
			i++;
	else if (str[i] == '>')
		while (str[i] == '>')
			i++;
	else if (str[i] == '|')
		while (str[i] == '|')
			i++;
	i--;
	(*count)++;
	if (str[i + 1] != ' ' && str[i + 1] != '\0')
		(*count)++;
	return (i);
}

char	*remove_quotes(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j])
	{	
		while (str[j] == '"')
		{
			j++;
			while (str[j] != '"')
				str[i++] = str[j++];
			j++;
		}
		while (str[j] == '\'')
		{
			j++;
			while (str[j] != '\'')
				str[i++] = str[j++];
			j++;
		}	
		str[i++] = str[j++];
	}
	str[i] = '\0';
	return (str);
}

int	*quotes_handling(char **cmd)
{
	int	i;
	int	*index;

	i = 0;
	while (cmd[i])
		i++;
	index = malloc(sizeof(int) * i);
	i = 0;
	while (cmd[i])
	{
		if (cmd[i][0] == '\'')
			index[i] = 1;
		else
			index[i] = 0;
		cmd[i] = remove_quotes(cmd[i]);
		i++;
	}
	return (index);
}
