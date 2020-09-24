/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:28:03 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 16:08:31 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			render_line(char *dest, char *src, char c)
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

void			render(t_field *field, char **array, char c)
{
	size_t		i;
	char		*tmp;

	i = 0;
	tmp = NULL;
	while (i < field->h)
	{
		tmp = bitoa(field->row[i], field->w);
		render_line(array[i], tmp, c);
		free(tmp);
		i++;
	}
}

char			**arr_init(size_t size, char c)
{
	char		**array;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	array = (char **)malloc(sizeof(char));
	while (i < size)
	{
		array[i] = (char *)malloc(sizeof(char) * size + 1);
		while (j < size)
		{
			array[i][j] = c;
			j++;
		}
		array[i][size] = '\0';
		j = 0;
		i++;
	}
	return (array);
}

void			render_output(t_program *program)
{
	size_t		i;
	size_t		size;
	char		c;
	t_field		*tmp;
	char		**array;

	i = 0;
	size = program->board->h;
	c = 'A' + program->block_count - 1;
	array = arr_init(size, '.');
	while (program->output)
	{
		tmp = program->output->content;
		render(tmp, array, c);
		program->output = program->output->next;
		c--;
	}
	i = 0;
	while (i < size)
	{
		ft_putstr(array[i]);
		ft_putchar('\n');
		i++;
	}
}
