/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:07:24 by esukava           #+#    #+#             */
/*   Updated: 2020/08/28 15:27:36 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
/*
	isvalid takes a .txt file as input. If it is a proper tetrimino field, 
	the program return 1. Otherwise the program returns 0.
*/
int			isproperline(char *line)
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
	row++;
	return (0);
}

int			isvalid(char *file)
{
	char			*line;
	size_t			r;
	int				fd;
	size_t			i;

	i = 1;
	fd = open(file, O_RDONLY);
	while ((r = ft_gnl(fd, &line)) > 0)
	{
		if (isproperline(line) == 0)
			return (0);
		i++;
	}
	if (i % 5 == 0)
		return (1);
	return (0);
}

