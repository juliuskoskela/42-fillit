/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:57:20 by esukava           #+#    #+#             */
/*   Updated: 2020/09/24 01:49:44 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				bf_fill(uint64_t *field, char *file, char one, size_t size)
{
	char		*line;
	int			r;
	int			fd;
	size_t		i;

	fd = open(file, O_RDONLY);
	i = 0;
	while ((r = ft_gnl(fd, &line)) > 0)
	{
		if (r < 0 || fd < 0 || fd > MAX_FD)
			return (0);
		if (line[0])
		{
			field[i] = readbits(line, one, size);
			free(line);
			i++;
		}
	}
	return (1);
}
