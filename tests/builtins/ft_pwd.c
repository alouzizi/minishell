/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:40:13 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/20 05:26:05 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(void)
{
	char	s[1024];

	getcwd(s, sizeof(s));
	ft_putstr_fd(s, 1);
	ft_putstr_fd("\n", 1);
}
