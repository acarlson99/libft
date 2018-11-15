/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:18:33 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/13 16:04:57 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int					print_unsigned(t_info info, va_list args_list)
{
	int			count;
	char		*str;
	size_t		n;

	count = 0;
	if (ft_isin('U', info.str))
		info.mod = PRINTF_LONG;
	n = extract_va_arg_unsigned(info, args_list);
	str = ft_size_ttoabase(n, 10);
	if (info.prec_spec && PREC == 0 && n == 0)
		info.len = 0;
	else
		info.len = ft_unumlen(n, 10);
	if (IS_SPACE(info.options))
	{
		count += ft_putchar_fd_2(' ', g_printf_fd);
		MFW--;
	}
	DO_IF(IS_NEG_FIELD(info.options), DO_IF(!(info.prec_spec) || PREC != 0\
		|| n != 0, count += print_int_precision(info, str, 0)));
	count += print_min_field_width(info, 0);
	DO_IF(!(IS_NEG_FIELD(info.options)), DO_IF(!(info.prec_spec) || PREC != 0 \
		|| n != 0, count += print_int_precision(info, str, 0)));
	free(str);
	return (count);
}
