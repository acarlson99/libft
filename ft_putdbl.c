/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 16:47:40 by acarlson          #+#    #+#             */
/*   Updated: 2018/10/24 16:50:56 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putdbl(double n, size_t precision)
{
	int		n1;
	size_t	p;
	size_t	len;

	p = precision;
	n1 = ft_floor(n);
	ft_putnbr(n1);
	n -= (double)n1;
	n = n < 0 ? -n : n;
	RET_NONE(p == 0);
	while ((double)ft_floor(n) != n && p > 0)
	{
		n *= 10;
		p--;
	}
	ft_putchar('.');
	n1 = ft_floor(n);
	len = ft_numlen(n1, 10);
	ft_putnbr(n1);
}
