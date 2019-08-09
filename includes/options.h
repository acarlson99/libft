/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:45:18 by acarlson          #+#    #+#             */
/*   Updated: 2019/08/08 13:28:51 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# include <stdlib.h>

struct	s_option {
	char	sopt;
	char	*lopt;
	char	*desc;
	int		code;
};

/*
** g_opts should be a null-terminating array of s_options
** opt_getopts - takes argc, argv, and an int ptr which will be set to
**			the end of the arg list. ii should be set to 1
** opt_printusage - prints usage given argv, containing the executable name
*/

int		opt_getopts(struct s_option **optab, int argc, char **argv, int *ii);
int		opt_getoptcode(struct s_option **optab, char c, char *s);
void	opt_printusage(struct s_option **optab, char **argv);

#endif
