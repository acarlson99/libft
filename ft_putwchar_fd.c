/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:11:32 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/13 20:11:44 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwchar_fd(wchar_t c, int fd)
{
	int		uni_len;

	uni_len = ft_unicode_len(c);
	if (uni_len == 1)
		return (ft_putchar_fd_2(c, fd));
	else if (uni_len == 2)
		return (ft_putchar_fd_2((c >> 6) + 0xC0, fd)\
						+ ft_putchar_fd_2(c & 0xBF, fd));
	else if (uni_len == 3)
		return (ft_putchar_fd_2((c >> 12) + 0xE0, fd)\
						+ ft_putchar_fd_2(((c >> 6) & 0x3F) + 0x80, fd)\
						+ ft_putchar_fd_2((c & 0x3F) + 0x80, fd));
	else if (uni_len == 4)
		return (ft_putchar_fd_2((c >> 18) + 0xF0, fd)\
						+ ft_putchar_fd_2(((c >> 12) & 0x3F) + 0x80, fd)\
						+ ft_putchar_fd_2(((c >> 6) & 0x3F) + 0x80, fd)\
						+ ft_putchar_fd_2((c & 0x3F) + 0x80, fd));
	return (uni_len);
}
