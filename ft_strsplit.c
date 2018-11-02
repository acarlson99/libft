/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:02:11 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/01 19:12:47 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ==72534== Invalid read of size 8
** 		==72534==    at 0x100003B72: main (main.c:227)
** ==72534==  Address 0x100ef3938 is 0 bytes after a block of size 8 alloc'd
** ==72534==    at 0x1001AE545: malloc (vg_replace_malloc.c:302)
** ==72534==    by 0x10000160E: ft_strsplit (in ./a.out)
** ==72534==    by 0x100003B4D: main (main.c:225)
*/

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	words;

	NULL_CHECK(!(s));
	i = -1;
	k = 0;
	words = ft_wordnum(s, c);
	NULL_CHECK(!(new = (char **)malloc((words + 1) * sizeof(*new))));
	while (++i < words)
	{
		j = 0;
		if (!(new[i] = ft_strnew(ft_wordlen(s + k, c) + 1)))
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
