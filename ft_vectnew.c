/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vectnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:27:29 by acarlson          #+#    #+#             */
/*   Updated: 2018/12/16 13:27:30 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vectnew(double x, double y, double z)
{
	t_vector	*new;

	new = (t_vector *)malloc(sizeof(t_vector));
	new->x = x;
	new->y = y;
	new->z = z;
	return (new);
}
