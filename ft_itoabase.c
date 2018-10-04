/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:11:48 by acarlson          #+#    #+#             */
/*   Updated: 2018/09/27 15:14:53 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_int_len(int n, int base)
{
	int count;

	count = 0;
	if (n < 0)
		count++;
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= base;
	}
	return (count);
}

char		*ft_itoabase(int n, int base)
{
	char	*new;
	int		is_neg;
	size_t	i;

	i = get_int_len(n, base);
	NULL_CHECK(!(new = (char *)malloc((i + 1) * sizeof(char))));
	new[i] = '\0';
	if (n == 0 && (is_neg = 0))
		new[--i] = '0';
	else if (n < 0)
	{
		new[--i] = -(n % base) < 10 ?\
-(n % base) + '0' : -(n % base) + 'a' - 10;
		n /= base;
		n = -n;
		is_neg = 1;
	}
	while (n != 0)
	{
		new[--i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	if (is_neg)
		new[--i] = '-';
	return (new);
}
