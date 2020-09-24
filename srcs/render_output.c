/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 14:28:03 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/25 01:09:38 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			render(t_field *field, char **array, char c)
{
	size_t		i;
	size_t		j;
	char		*tmp;

	i = 0;
	j = 0;
	while (i < field->h)
	{
		tmp = bitoa(field->row[i], field->w);
		while (array[i][j] != '\0')
		{
			if (tmp[j] == '1')
				array[i][j] = c;
			j++;
		}
		free(tmp);
		j = 0;
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
	array = (char **)malloc(sizeof(char *) * size);
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
	char		c;
	t_dlist		*ref;
	t_field		*tmp;
	char		**array;

	i = 0;
	ref = program->output;
	c = 'A' + program->block_count - 1;
	array = arr_init(program->board->h, '.');
	while (ref)
	{
		tmp = ref->content;
		render(tmp, array, c);
		bf_del(tmp);
		ref = ref->next;
		c--;
	}
	i = 0;
	while (i < program->board->h)
	{
		ft_putstr(array[i]);
		free(array[i]);
		ft_putchar('\n');
		i++;
	}
	dl_del_list(program->output);
	free(array);
}
