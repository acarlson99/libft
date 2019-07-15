/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:25:20 by acarlson          #+#    #+#             */
/*   Updated: 2019/07/15 13:29:46 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split_whitespace(char *s)
{
	unsigned	ii;

	if (!s)
		return (NULL);
	ii = 0;
	while (s[ii])
		if (ISWHITE(s[ii]))
			s[ii] = ' ';
	return (ft_strsplit(s, ' '));
}
