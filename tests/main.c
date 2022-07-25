/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:06:23 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/25 04:54:55 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	prompt_display(char **env)
{
	char	*s;

	while (1)
	{
		g_global.signal = 0;
		s = readline("minishell $ ");
		add_history(s);
		if (!s)
		{
			ft_putstr_fd(CTL_D, 1);
			exit (0);
		}
		if (!quotes_counting(s))
			execute(s, env);
		else
		{
			g_global.status = 258;
			ft_putstr_fd("Syntax Error : Check Quotes!\n", 2);
		}
		free(s);
	}
}

int	main(int ac, char **av, char **env)
{
	if (ac != 1 || av[1])
		return (1);
	ft_update_env(env);
	signals_handling();
	prompt_display(env);
}
