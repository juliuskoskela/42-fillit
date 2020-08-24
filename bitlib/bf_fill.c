/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:57:20 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 16:54:07 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"
#include "../libft/libft.h"

int				bf_fill(unsigned int *field, char *file, char one, size_t size)
{
	char		*line;
	int			r;
	int			fd;
	size_t		i;

	fd = open(file, O_RDONLY);
	i = 0;
	while ((r = ft_gnl(fd, &line)) > 0)
	{
		if (line[0])
		{
			field[i] = readbits(line, one, size);
			free(line);
			i++;
		}
	}
	return (1);
}
