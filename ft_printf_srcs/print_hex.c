/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:18:56 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/13 16:00:37 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

/*
** If X print capital letters rather than lowecase
*/

static int			print_hex_meat(t_info info, char *str, int n, int is_cap)
{
	int		count;

	count = 0;
	if (IS_ALT(info.options) && n != 0)
		MFW -= 2;
	if ((IS_NEG_FIELD(info.options) || IS_ZERO(info.options))\
		&& IS_ALT(info.options) && n != 0)
		count += ft_putstr_fd_2(is_cap ? "0X" : "0x", g_printf_fd);
	if (IS_NEG_FIELD(info.options))
		if (!(info.prec_spec) || PREC != 0 || n != 0)
			count += print_int_precision(info, str, 0);
	count += print_min_field_width(info, 0);
	if ((!(IS_NEG_FIELD(info.options) || IS_ZERO(info.options)))\
		&& IS_ALT(info.options) && n != 0)
		count += ft_putstr_fd_2(is_cap ? "0X" : "0x", g_printf_fd);
	if (!(IS_NEG_FIELD(info.options)))
		if (!(info.prec_spec) || PREC != 0 || n != 0)
			count += print_int_precision(info, str, 0);
	return (count);
}

int					print_hex(t_info info, va_list args_list)
{
	char	*str;
	char	*ptr;
	int		count;
	int		is_cap;
	size_t	n;

	n = extract_va_arg_unsigned(info, args_list);
	str = ft_size_ttoabase(n, 16);
	is_cap = ft_isin('X', info.str);
	if (is_cap)
	{
		ptr = str - 1;
		while (*++ptr)
			*ptr = TOUPPER(*ptr);
	}
	count = 0;
	if (info.prec_spec && PREC == 0 && n == 0)
		info.len = 0;
	else
		info.len = ft_unumlen(n, 16);
	count += print_hex_meat(info, str, n, is_cap);
	free(str);
	return (count);
}
