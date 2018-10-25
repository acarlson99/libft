/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflt_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 14:18:57 by acarlson          #+#    #+#             */
/*   Updated: 2018/10/25 14:19:39 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putflt_fd(float n, size_t precision, int fd)
{
	int		n1;
	size_t	p;
	size_t	len;

	p = precision;
	n1 = ft_floor(n);
	ft_putnbr_fd(n1, fd);
	n -= (float)n1;
	n = n < 0 ? -n : n;
	RET_NONE(p == 0);
	while (p > 0)
	{
		n *= 10;
		p--;
	}
	ft_putchar_fd('.', fd);
	n1 = ft_floor(n);
	len = ft_numlen(n1, 10);
	while (len++ < precision)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(n1, fd);
}
