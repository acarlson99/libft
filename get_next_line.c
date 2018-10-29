/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 16:03:49 by acarlson          #+#    #+#             */
/*   Updated: 2018/10/28 21:20:12 by acarlson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			loop(int fd, char **line, char buf[BUFF_SIZE], int nl)
{
	ssize_t			rret;
	char			*tmp1;
	char			*tmp2;
	size_t			len;

	while (!(nl) && rret > 0)
	{
		rret = read(fd, buf, BUFF_SIZE);
		len = 0;
		while (len < BUFF_SIZE && buf[len] != '\n')
			len++;
		if (buf[len] == '\n')
			nl = 1;
		tmp2 = ft_strndup(buf, len);
		tmp1 = ft_strjoin(*line, tmp2);
		free(*line);
		*line = tmp1;
		free(tmp2);
		ft_bzero(buf, len + nl);
	}
}

static size_t		find_i(char buf[BUFF_SIZE], size_t *i)
{
	*i = 0;
	while (*i < BUFF_SIZE && buf[*i] == 0)
		*i = *i + 1;
	if (*i == BUFF_SIZE)
	{
		*i = 0;
		return (1);
	}
	return (0);
}

static size_t		find_len(char buf[BUFF_SIZE], size_t i)
{
	size_t len;

	len = 0;
	while (i + len < BUFF_SIZE && buf[i + len] != '\n')
		len++;
	return (len);
}

int					get_next_line(const int fd, char **line)
{
	static char		buf[4096][BUFF_SIZE];
	size_t			i;
	size_t			len;
	ssize_t			rret;
	int				nl;

	RET_IF(fd < 0 || !(line) || BUFF_SIZE < 1, -1);
	rret = BUFF_SIZE;
	nl = 0;
	if (find_i(buf[fd], &i))
	{
		RET_IF((rret = read(fd, buf[fd], BUFF_SIZE)) == -1, -1);
		RET_IF(rret == 0, 0);
	}
	len = find_len(buf[fd], i);
	*line = ft_strndup(buf[fd] + i, len);
	if (buf[fd][i + len] == '\n')
	{
		len++;
		nl = 1;
	}
	ft_bzero(buf[fd] + i, len);
	loop(fd, line, buf[fd], nl);
	return (1);
}
