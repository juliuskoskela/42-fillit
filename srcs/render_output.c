/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 05:30:06 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/09 05:30:46 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*bitoa(uint64_t nb, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	str = ft_strnew(len + 1);
	str[len] = '\0';
	while (str[i])
	{
		if (checkbit(nb, i) == 1)
		{
			str[i] = '1';
			i++;
		}
		else
		{
			str[i] = '0';
			i++;
		}
	}
	return (str);
}

void		bf_write(t_field *field, char **array, char c)
{
	size_t		i;

	i = 0;
	while (i < field->h)
	{
		*array[i] = bitoa
		i++;
	}
}

void		render_output(t_dlist *output, size_t block_count)
{
	size_t		i;
	char		c;
	t_field		*tmp;
	char		**array;

	i = 0;
	c = 'A';
	tmp = output->content;
	array = (char **)malloc(sizeof(char) * tmp->h);
	while (i < block_count)
	{
		bf_write(tmp, array, c);
	}
}
