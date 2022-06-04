/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooumlil <ooumlil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 12:17:38 by ooumlil           #+#    #+#             */
/*   Updated: 2022/06/04 20:17:57 by ooumlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static size_t	ft_wlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static size_t	ft_wcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		l;
	char	*c;

	i = 0;
	l = ft_strlen(s1);
	c = (char *)malloc(sizeof(char) * l + 1);
	if (!c)
		return (NULL);
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len < ft_strlen(s + start))
		str = malloc(len + 1);
	else
		str = malloc(ft_strlen(s) - start + 1);
	if (!str)
		return (NULL);
	while (s[start] && i < len)
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**arr;

	if (!s)
		return (NULL);
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_wcount(s, c) + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		i = ft_wlen(s, c);
		if (*s != c && *s)
			arr[j++] = ft_substr(s, 0, i);
		if (*s && (!arr[j - 1]))
			ft_free(arr);
		s += i;
	}
	arr[j] = NULL;
	return (arr);
}