/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 14:59:26 by acarlson          #+#    #+#             */
/*   Updated: 2019/08/07 15:00:42 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_hashn(char *input, size_t size)
{
	size_t	hash;
	size_t	ii;

	ii = 0;
	hash = FVN_OFFSET_BASIS;
	while (input[ii] && ii < size)
	{
		hash = hash * FVN_PRIME;
		hash = hash ^ input[ii];
		++ii;
	}
	return (hash);
}
