/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:06:23 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/03 13:10:55 by ooumlil          ###   ########.fr       */
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

int	cmd_history(void)
{
	int		fd;
	char	*s;

	fd = open(".history.txt", O_CREAT | O_RDWR);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		add_history(s);
	}
	return (fd);
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

int	main(void)
{
	char	*s;
	int		fd;

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &ctl_c);
	rl_catch_signals = 0;
	while (1)
	{
		fd = cmd_history();
		s = readline("minishell $ ");
		if (!s)
		{
			ft_putstr_fd("\033[A\033[12Cexit\n",1);
			exit (0);
		}
		if (s[0])
		{
			ft_putstr_fd(s, fd);
			ft_putstr_fd("\n", fd);
		}
	}
}
