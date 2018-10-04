/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:54:41 by acarlson          #+#    #+#             */
/*   Updated: 2018/09/25 19:20:32 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(const char *s)
{
	int		s_len;
	char	*new;
	char	*ptr;

	s_len = ft_strlen(s);
	NULL_CHECK(!(new = (char *)malloc((s_len + 1) * sizeof(char))));
	ptr = new;
	while (*s)
		s++;
	s--;
	while (*s)
		*ptr++ = *s--;
	*ptr = '\0';
	return (new);
}
