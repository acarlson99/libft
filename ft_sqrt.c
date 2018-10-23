/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:50:16 by acarlson          #+#    #+#             */
/*   Updated: 2018/10/23 15:19:53 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

double		ft_sqrt(double n)
{
	double old;
	double new;

	old = n;
	new = 0;
	while (old != 0)
	{
		printf("NEW %lf OLD %lf\n", new, old);
        new = 0.5 * (old + (n / old));
		if (((ABS(new - old)) / old) < 0.0001)
		{
			printf("BREAKING %lf %lf %lf %lf\n", new, old, new - old, ABS(new - old));
			printf("wtf %lf %lf\n", (ABS(new - old)), (ABS(new - old)) / old);
			break ;
		}
		old = new;
	}
	return (new);
}
