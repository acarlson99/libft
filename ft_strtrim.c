/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 22:37:25 by acarlson          #+#    #+#             */
/*   Updated: 2018/09/24 18:28:00 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		end;
	int		start;
	int		i;

	start = 0;
	if (s)
	{
		end = ft_strlen(s) - 1;
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
		NULL_CHECK(!(new = (char *)malloc(((end < start)\
		? 1 : (end - start + 2) * sizeof(char)))));
		i = 0;
		while (start <= end)
			new[i++] = s[start++];
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
