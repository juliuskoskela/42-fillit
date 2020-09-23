/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 18:22:22 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 02:38:17 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_dlist			*read_input(char *file, char one)
{
	char		*line;
	t_dlist		*head;
	t_field		*block;
	int			fd;
	size_t		i;

	i = 0;
	head = NULL;
	fd = open(file, O_RDONLY);
	block = bf_new(4, 4);
	dl_putfirst(&head, block);
	while ((ft_gnl(fd, &line)) > 0)
	{
		if (i == 4)
		{
			i = 0;
			normalize_block(block);
			block = bf_new(4, 4);
			dl_putlast(&head, block);
			free(line);
		}
		else
		{
			block->row[i] = readbits(line, one, block->w);
			free(line);
			i++;
		}
	}
	normalize_block(block);
	close(fd);
	return (head);
}
