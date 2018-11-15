/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:03:45 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/14 14:58:38 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static const t_fun_ptr g_get_function[] =
{
	['s'] = print_string,
	['S'] = print_string,
	['p'] = print_pointer,
	['d'] = print_int,
	['D'] = print_int,
	['i'] = print_int,
	['o'] = print_oct,
	['O'] = print_oct,
	['u'] = print_unsigned,
	['U'] = print_unsigned,
	['x'] = print_hex,
	['X'] = print_hex,
	['c'] = print_char,
	['C'] = print_char,
	['b'] = print_bin,
	['%'] = print_percent
};

int		dispatch_func(const char *fmt, int *count, va_list args_list)
{
	t_info	info;
	int		n;
	char	c;

	n = ft_strcspn(fmt, CONVERSIONS);
	c = fmt[n];
	info.options = find_options(c, fmt);
	info.mod = find_modifier(c, fmt, n);
	RET_IF(info.options == -1 || info.mod == -1, ft_strspn(fmt, RECOGNIZED));
	info.str = ft_strndup(fmt, n + 1);
	info.min_field_width = get_min_field(info.str);
	info.prec_spec = ft_isin('.', info.str);
	info.precision = info.prec_spec ? get_precision(info) : 0;
	if (info.prec_spec && c != '%')
	{
		info.options |= ZERO;
		info.options ^= ZERO;
	}
	*count = *count + g_get_function[(int)c](info, args_list);
	free(info.str);
	return (n + 1);
}
