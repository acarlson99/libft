/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:15:44 by acarlson          #+#    #+#             */
/*   Updated: 2018/09/15 19:40:22 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*hay_copy;
	int		i;
	int		j;
	int		i2;

	hay_copy = (char *)haystack;
	i = 0;
	if (*needle == '\0')
		return (hay_copy);
	while (hay_copy[i])
	{
		j = 0;
		i2 = i;
		while (needle[j] && hay_copy[i2] == needle[j])
		{
			j++;
			i2++;
			if (needle[j] == '\0')
				return (hay_copy + i);
		}
		i++;
	}
	return (NULL);
}
