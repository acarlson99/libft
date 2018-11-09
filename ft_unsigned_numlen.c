/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_tlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:11:56 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/09 12:15:12 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns number of digits in some number n in some base
*/

size_t		ft_unsigned_numlen(size_t n, int base)
{
	size_t		count;

	count = 0;
	RET_IF(n == 0, 0);
	while (n != 0)
	{
		count++;
		n /= base;
	}
	return (count);
}
