/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:44:34 by acarlson          #+#    #+#             */
/*   Updated: 2019/08/08 13:32:37 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	opt_getstr(struct s_option **optab, char *s)
{
	unsigned ii;

	ii = 0;
	while (optab[ii])
	{
		if (optab[ii]->lopt && !ft_strcmp(optab[ii]->lopt, s))
			return (optab[ii]->code);
		++ii;
	}
	ft_printf("Invalid option: --%s\n", s);
	exit(1);
}

static int	opt_getchars(struct s_option **optab, char *s)
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
		while (optab[ii])
		{
			if (optab[ii]->sopt == s[si])
			{
				opt = optab[ii]->code;
				break ;
			}
			++ii;
		}
		DO_IF(opt <= 0 && ft_printf("Invalid option: -%c\n", s[si]), exit(1));
		allopts |= opt;
	}
	return (allopts);
}

int			opt_getopts(struct s_option **optab, int argc, char **argv, int *ii)
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
				opt = opt_getstr(optab, &argv[*ii][2]);
			else
			{
				*ii = *ii + 1;
				break ;
			}
		else if (argv[*ii][1])
			opt = opt_getchars(optab, &argv[*ii][1]);
		else
			break ;
		allopts |= opt;
		*ii = *ii + 1;
	}
	return (allopts);
}

int			opt_getoptcode(struct s_option **optab, char c, char *s)
{
	unsigned ii;

	ii = -1;
	while (optab[++ii])
	{
		if ((c && optab[ii]->sopt == c)
			|| (s && !ft_strcmp(optab[ii]->lopt, s)))
			return (optab[ii]->code);
	}
	return (-1);
}

void		opt_printusage(struct s_option **optab, char **argv)
{
	unsigned ii;

	ii = -1;
	ft_printf("Usage: %s [OPTIONS] files\n", argv[0]);
	while (optab[++ii])
		ft_printf("\t-%c, --%-20s\t%s\n", optab[ii]->sopt, optab[ii]->lopt,
				optab[ii]->desc);
}
