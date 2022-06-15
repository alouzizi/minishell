/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:06:23 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/15 09:21:41 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt_display(char **env)
{
	char	*s;

	while (1)
	{
		g_global.l = 0;
		s = readline("minishell $ ");
		add_history(s);
		if (!s)
		{
			ft_putstr_fd(CTL_D, 1);
			exit (0);
		}
		execute(s, env);
	}
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1)
		return (1);
	signal(SIGINT, &ctl_c);
	signal(SIGQUIT, SIG_IGN);
	rl_catch_signals = 0;
	prompt_display(env);
}
