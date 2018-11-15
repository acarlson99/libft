/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:18:32 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/14 14:37:37 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdio.h>

int		g_printf_fd = 1;

int		ft_vdprintf(int fd, const char *format, va_list args_list)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	g_printf_fd = fd;
	while (format[i])
	{
		if (format[i] == '%')
			i += dispatch_func(&(format[i + 1]), &count, args_list);
		else if (format[i] == '{')
			i += find_colors(&(format[i + 1]));
		else
			count += ft_putchar_fd_2(format[i], fd);
		i++;
	}
	va_end(args_list);
	return (count);
}

int		ft_printf(char *fmt, ...)
{
	va_list args;
	int		n;

	va_start(args, fmt);
	n = ft_vdprintf(1, fmt, args);
	va_end(args);
	return (n);
}
