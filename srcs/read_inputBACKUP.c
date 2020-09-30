/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:22:22 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/25 01:26:21 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		val_line(char *line, int row)
{
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
				return (row);
			}
	if (l == 0)
	{
		row++;
		return (row);
	}
	return (0);
}

t_dlist			*read_input(char *file, char one)
{
	char		*line;
	t_dlist		*head;
	t_field		*block;
	int			row;
	int			fd;
	size_t		i;

	i = 0;
	head = NULL;
	fd = open(file, O_RDONLY);
	block = bf_new(4, 4);
	dl_putfirst(&head, block);
	row = 0;
	while ((ft_gnl(fd, &line)) > 0)
	{
		if (!(val_line(line, row)))
			error("error\n");
		if (i == 4)
		{
			i = 0;
			normalize_block(block);
			block = bf_new(4, 4);
			dl_putlast(&head, block);
		}
		else
		{
			block->row[i] = readbits(line, one, block->w);
			i++;
		}
		free(line);
	}
	normalize_block(block);
	close(fd);
	return (head);
}
