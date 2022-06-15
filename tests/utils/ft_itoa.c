/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:15:52 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/15 12:10:35 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static size_t	tot_dig(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	sl;
	long	d;
	char	*s;

	sl = tot_dig(n);
	d = n;
	s = malloc(sl + 1);
	if (!s)
		return (NULL);
	while (d < 0)
	{
		s[0] = '-';
		d = d * -1;
	}
	if (d == 0)
		s[0] = '0';
	s[sl--] = '\0';
	while (d != 0)
	{
		s[sl] = d % 10 + '0';
		sl--;
		d = d / 10;
	}
	return (s);
}
