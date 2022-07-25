/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 03:09:46 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/25 04:54:39 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctl_c(int signum)
{
	if (signum == SIGINT && !g_global.signal)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signum == SIGINT && g_global.signal)
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signals_handling(void)
{
	signal(SIGINT, &ctl_c);
	signal(SIGQUIT, SIG_IGN);
	rl_catch_signals = 0;
}