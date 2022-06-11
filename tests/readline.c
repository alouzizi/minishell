/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:06:23 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/11 02:59:11 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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

void	ctl_c(int signum)
{
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	main(int ac, char **av, char **env)
{
	char	*s;

	(void)ac;
	(void)av;
	signal(SIGINT, &ctl_c);
	signal(SIGQUIT, SIG_IGN);
	rl_catch_signals = 0;
	while (1)
	{
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
