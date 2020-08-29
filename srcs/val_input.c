/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 01:52:29 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/30 01:52:31 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		val_line(char *line)
{
	static int		row;
	size_t			i;
	size_t			l;

	i = 0;
	l = ft_strlen(line);
	if (!row)
		row = 1;
	if (row % 5 != 0)
		while (l == 4 && (line[i] == '#' || line[i] == '.'))
			if (++i >= 4)
			{
				row++;
				return (1);
			}
	if (l == 0)
	{
		row++;
		return (1);
	}
	return (0);
}

int			val_input(char *file)
{
	char			*line;
	size_t			r;
	int				fd;
	size_t			i;

	i = 0;
	fd = open(file, O_RDONLY);
	while ((r = ft_gnl(fd, &line)) > 0)
	{
		if (val_line(line) == 0)
			return (0);
		i++;
	}
	if (i % 5 == 0)
		return (1);
	close(fd);
	return (0);
}