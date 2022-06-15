/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:38:34 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/15 07:22:51 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	ft_putstr_fd(s, 1);
	write (fd, "\n", 1);
}

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
