/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 20:54:36 by acarlson          #+#    #+#             */
/*   Updated: 2018/10/25 19:25:15 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*new_str;

	NULL_CHECK(!(new_str = (char *)ft_memalloc(size + 1)));
	ft_bzero(new_str, size + 1);
	return (new_str);
}
