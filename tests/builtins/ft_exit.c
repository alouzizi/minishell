/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 08:16:26 by ooumlil           #+#    #+#             */
/*   Updated: 2022/07/25 05:59:00 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	arg_isdigit(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] >= '0' || s[i] <= '9')
			return (1);
	}
	return (0);
}

long long	a_to_ll(char *str)
{
	int			i;
	int			sign;
	long double	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (sign * result);
}

void	ft_exit(char **cmd)
{
	long long	max;
	long long	min;

	if (!cmd[1])
	{
		ft_putendl_fd("exit", 1);
		exit (0);
	}
	else if (arg_isdigit(cmd[1]) && !cmd[2] \
		&& (a_to_ll(cmd[1]) >= min && a_to_ll(cmd[1]) <= max))
	{
		ft_putendl_fd("exit", 1);	
		exit(a_to_ll(cmd[1]));
	}
	else if (!cmd[2]
	)
	{
		ft_putendl_fd("exit", 1);
		printf("minishell: exit: %s: numeric argument required\n", cmd[1]);
		exit(0);
	}
	ft_putendl_fd("exit\nminishell: exit: too many arguments", 1);
}
