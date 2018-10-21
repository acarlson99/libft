/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 17:27:54 by acarlson          #+#    #+#             */
/*   Updated: 2018/10/20 20:49:05 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putflt(float n, size_t precision)
{
	int n1;

	(void)precision;
	n1 = ft_floor(n);
	ft_putnbr(n);
	n -= (float)n1;
	n = n < 0 ? -n : n;
	while ((float)ft_floor(n) != n)
		n *= 10;
	ft_putchar('.');
	ft_putnbr(n);
}
