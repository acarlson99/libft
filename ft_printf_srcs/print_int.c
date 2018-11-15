/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:17:29 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/13 15:50:49 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int			print_int_meat(t_info info, size_t n, char *str, int is_neg)
{
	int count;

	count = 0;
	if (IS_NEG_FIELD(info.options))
		if (!(info.prec_spec) || PREC != 0 || n != 0)
			count += print_int_precision(info, str, is_neg);
	count += print_min_field_width(info, is_neg);
	if (!(IS_NEG_FIELD(info.options)))
		if (!(info.prec_spec) || PREC != 0 || n != 0)
			count += print_int_precision(info, str, is_neg);
	return (count);
}

int					print_int(t_info info, va_list args_list)
{
	int			count;
	int			is_neg;
	char		*str;
	ssize_t		n;

	count = 0;
	if (ft_isin('D', info.str))
		info.mod = PRINTF_LONG;
	n = extract_va_arg_signed(info, args_list);
	str = ft_ssize_ttoabase(n, 10);
	is_neg = n < 0;
	if (is_neg && IS_SPACE(info.options))
		info.options -= SPACE;
	if (info.prec_spec && PREC == 0 && n == 0)
		info.len = 0;
	else
		info.len = ft_snumlen(n, 10) - is_neg;
	DO_IF(IS_SPACE(info.options), count += ft_putchar_fd_2(' ', g_printf_fd));
	DO_IF(IS_SPACE(info.options), MFW--);
	MFW -= is_neg || IS_SIGNED(info.options);
	count += print_int_meat(info, n, str, is_neg);
	free(str);
	return (count);
}
