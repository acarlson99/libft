/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:22:04 by acarlson          #+#    #+#             */
/*   Updated: 2019/07/15 13:24:34 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define FVN_OFFSET_BASIS 0xcbf29ce484222325
#define FVN_PRIME 0x100000001b3

size_t		ft_hash(char *input)
{
	size_t	hash;
	size_t	ii;

	ii = 0;
	hash = FVN_OFFSET_BASIS;
	while (input[ii])
	{
		hash = hash * FVN_PRIME;
		hash = hash ^ input[ii];
		++ii;
	}
	return (hash);
}
