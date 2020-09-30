/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:22:22 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/30 18:07:12 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		val_line(char *line)
{
	size_t		i;

	i = 0;
	if (ft_strlen(line) == 4)
	{
		while (i < 4)
		{
			if (line[i] == '#' || line[i] == '.')
				i++;
			else
				return (0);
		}
	}
	else
		return (0);
	return (i);
}

static t_field	*createblock(t_dlist *head, t_field *block)
{
	normalize_block(block);
	block = bf_new(4, 4);
	dl_putlast(&head, block);
	return (block);
}

t_dlist			*read_input(char *file, char one, size_t i)
{
	char		*line;
	t_dlist		*head;
	t_field		*block;
	int			fd;

	head = NULL;
	fd = open(file, O_RDONLY);
	block = bf_new(4, 4);
	dl_putfirst(&head, block);
	while ((ft_gnl(fd, &line)) > 0)
	{
		if ((i == 4 && line[0] != '\0') || (i != 4 && !(val_line(line))))
			error("error\n");
		if (i == 4)
		{
			i = 0;
			block = createblock(head, block);
		}
		else
			block->row[i++] = readbits(line, one, block->w);
		free(line);
	}
	normalize_block(block);
	close(fd);
	return (head);
}
