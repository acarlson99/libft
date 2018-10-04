/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 20:13:04 by acarlson          #+#    #+#             */
/*   Updated: 2018/09/15 20:45:21 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *s_cpy;

	s_cpy = (char *)s;
	while (*s_cpy)
		s_cpy++;
	while (s_cpy >= s)
	{
		if (*s_cpy == c)
			return (s_cpy);
		s_cpy--;
	}
	return (NULL);
}
