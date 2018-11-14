/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:10:38 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/13 20:13:26 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unicode_len(wchar_t c)
{
	RET_IF(c < 0x80, 1);
	RET_IF(c < 0x800, 2);
	RET_IF(c < 0x1000, 3);
	RET_IF(c < 0x110000, 4);
	return (0);
}
