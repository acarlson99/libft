/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 14:28:09 by acarlson          #+#    #+#             */
/*   Updated: 2018/11/14 15:02:48 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			find_colors(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strcspn(s, "}");
	str = ft_strndup(s, len);
	if (!(ft_strcmp(str, "red")))
		ft_putstr_fd(FG_RED, PF_FD);
	else if (!(ft_strcmp(str, "green")))
		ft_putstr_fd(FG_GRN, PF_FD);
	else if (!(ft_strcmp(str, "blue")))
		ft_putstr_fd(FG_BLU, PF_FD);
	else
		ft_putstr_fd(NC, PF_FD);
	free(str);
	return (len + 1);
}
