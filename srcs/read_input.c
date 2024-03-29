/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:22:22 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/30 19:11:13 by jkoskela         ###   ########.fr       */
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

t_dlist			*read_input(char *file, t_dlist *head, char one, size_t i)
{
	t_field		*block;
	char		*line;
	int			fd;
	int			r;

	block = bf_new(4, 4);
	fd = open(file, O_RDONLY);
	dl_putfirst(&head, block);
	while ((r = ft_gnl(fd, &line)) > 0)
	{
		if ((r == 2 && line[0] != '\0') || (i == 4 && line[0] != '\0') \
									|| (i != 4 && !(val_line(line))))
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
