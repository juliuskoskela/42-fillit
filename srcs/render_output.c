/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:28:03 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/21 14:28:11 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		render_line(char *dest, char *src, char c)
{
	size_t		i;

	i = 0;

	while (dest[i] != '\0')
	{
		if (src[i] == '1')
			dest[i] = c;
		i++;
	}
}

void		render(t_field *field, char **array, char c)
{
	size_t		i;
	char		*tmp;

	i = 0;
	while (i < field->h)
	{
		tmp = bitoa(field->row[i], field->w);
		render_line(array[i], tmp, c);
		free(tmp);
		i++;
	}
}

void			render_output(t_program *Program)
{
	size_t		i;
	size_t		j;
	size_t		size;
	char		c;
	t_field		*tmp;
	char		**array;

	i = 0;
	j = 0;
	size = Program->board->h;
	c = 'A';
	array = (char **)malloc(sizeof(char) *  size + 1);
	while (i < size)
	{
		array[i] = ft_calloc(size + 1, sizeof(char));
		while (j < size)
		{
			array[i][j] = '.';
			j++;
		}
		array[i][size] = '\n';
		array[i][size + 1] = '\0';
		j = 0;
		i++;
	}
	i = 0;
	while (Program->output)
	{
		tmp = Program->output->content;
		render(tmp, array, c);
		Program->output = Program->output->next;
		c++;
	}
	i = 0;
	while (i < size)
	{
		ft_putstr(array[i]);
	 	i++;
	}
}
