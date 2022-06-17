/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:11:21 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/16 15:10:05 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quotes_counting(char *s)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] && s[i] == '\'')
		{
			i++;
			count++;
			while (s[i] && s[i] != '\'')
				i++;
		}
		else if (s[i] && s[i] == '"')
		{
			i++;
			count++;
			while (s[i] && s[i] != '"')
				i++;
		}
		if (s[i] == '\'' || s[i] == '"')
			count++;
	}
	return (count % 2);
}
