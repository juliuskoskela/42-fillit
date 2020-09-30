/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 00:32:25 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/30 18:20:20 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		eof(char **mem, char **line, int r)
{
	if (r == 0 && *mem[0] != '\0')
	{
		*line = ft_strdup(*mem);
		ft_strdel(&*mem);
		return (2);
	}
	else
		return (0);
}

static int		readbuf(char **mem, char **line, int fd)
{
	char			*tmp;
	char			buff[BUFF_SIZE + 1];
	int				r;

	while ((r = read(fd, buff, BUFF_SIZE)))
	{
		if (r == -1)
			return (-1);
		buff[r] = '\0';
		tmp = ft_strjoin(*mem, buff);
		ft_strdel(&*mem);
		if (!(ft_strchr(buff, '\n')))
			*mem = tmp;
		else
		{
			*line = ft_strcdup(tmp, '\n');
			*mem = ft_strcsub(buff, '\n');
			free(tmp);
			return (1);
		}
	}
	return (eof(&*mem, &*line, r));
}

int				ft_gnl(const int fd, char **line)
{
	static char		*mem[MAX_FD];
	char			*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!mem[fd])
		mem[fd] = ft_strnew(0);
	if ((ft_strchr(mem[fd], '\n')))
	{
		*line = ft_strcdup(mem[fd], '\n');
		tmp = ft_strcsub(mem[fd], '\n');
		ft_strdel(&mem[fd]);
		mem[fd] = tmp;
		return (1);
	}
	return (readbuf(&mem[fd], &*line, fd));
}
