/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 01:07:34 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/22 08:13:34 by ooumlil          ###   ########.fr       */
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
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_data
{
	int	l;
}	t_data;

t_data	g_global;

int		quotes_counting(char *s);

void	free_arr(char **arr);

//signals
void	ctl_c(int signum);
void	sig_reset(void);

//pwd
void	ft_pwd(void);

//echo
void	ft_echo(char **cmd);

//env
void	shlvl_handling(char **env, int i);
void	ft_update_env(char **env);
void	ft_env(char **env);

//export
char	**ft_arr_copy(char **arr);
void	sort_array_alphabetically(char **arr);
int		arr_len(char **arr);
void	add_var_to_env(char *var, char **env);
void	add_to_value(char *arg, char **env, int i, int ptr);
void	add_to_env(char *var, char **env);
void	add_variable(char *arg, char **env);
void	add_to_export(char **env, char **cmd);
void	sort_array_alphabetically(char **arr);
void	print_export(char **arr);
void	ft_export(char **cmd, char **env);

//unset
void	ft_unset(char **cmd, char **env);

//cd
void	ft_cd(char **cmd, char **env);

//executing
char	**get_path(char *s, char **env);
void	ft_minishell(char **cmd, char **env);
int		builtincmp(char *s1, char *s2);
int		isbuiltin(char **cmd, char **env);
void	execute(char *s, char **env);
void	commands_execution(char **path, char **cmd, char **env);

#endif
