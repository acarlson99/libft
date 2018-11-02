/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 18:11:48 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/01 19:13:09 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ==72534== Conditional jump or move depends on uninitialised value(s)
** ==72534==    at 0x1000022EE: ft_itoabase (in ./a.out)
** ==72534==    by 0x100002DB0: main (main.c:21)
** ==72534==
** ==72534== Invalid write of size 1
** ==72534==    at 0x100002307: ft_itoabase (in ./a.out)
** ==72534==    by 0x100002DB0: main (main.c:21)
** ==72534==  Address 0x100ef2a2f is 1 bytes before a block of size 4 alloc'd
** ==72534==    at 0x1001AE545: malloc (vg_replace_malloc.c:302)
** ==72534==    by 0x100002160: ft_itoabase (in ./a.out)
** ==72534==    by 0x100002DB0: main (main.c:21)
** ==72534==
*/

char		*ft_itoabase(int n, int base)
{
	char	*new;
	int		is_neg;
	size_t	i;

	i = ft_numlen(n, base);
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
