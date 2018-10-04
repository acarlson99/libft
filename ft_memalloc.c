/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 20:28:42 by acarlson          #+#    #+#             */
/*   Updated: 2018/09/16 20:47:01 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*thing;

	NULL_CHECK(!(thing = (void *)malloc(size)));
	ft_bzero(thing, size);
	return (thing);
	return (NULL);
}
