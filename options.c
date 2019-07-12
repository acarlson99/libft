/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:44:34 by acarlson          #+#    #+#             */
/*   Updated: 2019/07/12 13:45:19 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	opt_getstr(char *s)
{
	unsigned ii;

	ii = 0;
	while (g_opts[ii])
	{
		if (g_opts[ii]->lopt && !ft_strcmp(g_opts[ii]->lopt, s))
			return (g_opts[ii]->code);
		++ii;
	}
	ft_printf("Invalid option: --%s\n", s);
	exit(1);
}

static int	opt_getchars(char *s)
{
	unsigned	si;
	unsigned	ii;
	int			opt;
	int			allopts;

	si = -1;
	allopts = 0;
	while (s[++si])
	{
		ii = 0;
		opt = 0;
		while (g_opts[ii])
		{
			if (g_opts[ii]->sopt == s[si])
			{
				opt = g_opts[ii]->code;
				break ;
			}
			++ii;
		}
		if (opt <= 0)
			ft_printf("Invalid option: -%c\n", s[si]);
		allopts |= opt;
	}
	return (allopts);
}

int			opt_getopts(int argc, char **argv, int *ii)
{
	int allopts;
	int opt;

	allopts = 0;
	while (*ii < argc)
	{
		opt = 0;
		if (*argv[*ii] != '-')
			break ;
		else if (argv[*ii][1] == '-')
			if (argv[*ii][2])
				opt = opt_getstr(&argv[*ii][2]);
			else
			{
				*ii = *ii + 1;
				break ;
			}
		else if (argv[*ii][1])
			opt = opt_getchars(&argv[*ii][1]);
		else
			break ;
		allopts |= opt;
		*ii = *ii + 1;
	}
	return (allopts);
}

int			opt_getoptcode(char c, char *s)
{
	unsigned ii;

	ii = -1;
	while (g_opts[++ii])
	{
		if ((c && g_opts[ii]->sopt == c)
			|| (s && !ft_strcmp(g_opts[ii]->lopt, s)))
			return (g_opts[ii]->code);
	}
	return (-1);
}

void		opt_printusage(char **argv)
{
	unsigned ii;

	ii = -1;
	ft_printf("Usage: %s [OPTIONS] files\n", argv[0]);
	while (g_opts[++ii])
		ft_printf("\t-%c, --%-20s\t%s\n", g_opts[ii]->sopt, g_opts[ii]->lopt,
				g_opts[ii]->desc);
}
