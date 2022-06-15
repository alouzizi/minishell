/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:07:34 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/15 11:16:28 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define CTL_D "\033[A\033[12Cexit\n"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <signal.h>
# include <fcntl.h>
# include <termios.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	int	l;
}	t_data;

t_data	g_global;

void	ctl_c(int signum);
char	**get_path(char *s, char **env);
void	ft_minishell(char **cmd, char **env);
void	ft_pwd(void);
void	ft_echo(char **cmd);
int		arr_len(char **arr);
char	**ft_arr_copy(char **arr);
void	ft_env(char **env);
int		builtincmp(char *s1, char *s2);
int		isbuiltin(char **cmd, char **env);
void	execute(char *s, char **env);
void	commands_execution(char **path, char **cmd, char **env);

#endif
