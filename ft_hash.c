/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:22:04 by acarlson          #+#    #+#             */
/*   Updated: 2019/09/05 12:50:33 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_hash(char *input)
{
	size_t	hash;
	size_t	ii;

	ii = 0;
	hash = FNV_OFFSET_BASIS;
	while (input[ii])
	{
		hash = hash * FNV_PRIME;
		hash = hash ^ input[ii];
		++ii;
	}
	return (hash);
}
