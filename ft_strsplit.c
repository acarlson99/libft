/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:02:11 by acarlson          #+#    #+#             */
/*   Updated: 2018/09/30 16:08:59 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words(const char *s, char c)
{
	size_t w;

	w = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		if (*s && *s != c)
			w++;
		while (*s && *s != c)
			s++;
	}
	return (w);
}

static size_t	word_len(const char *s, char c)
{
	size_t len;

	len = 0;
	while (*s == c)
		s++;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	j;
	size_t	k;

	NULL_CHECK(!(s));
	i = -1;
	k = 0;
	NULL_CHECK(!(new = (char **)malloc((words(s, c) + 1) * sizeof(*new))));
	while (++i < words(s, c))
	{
		j = 0;
		if (!(new[i] = ft_strnew(word_len(s + k, c) + 1)))
			new[i] = NULL;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
			new[i][j++] = s[k++];
		new[i][j] = '\0';
	}
	new[i] = 0;
	return (new);
}
