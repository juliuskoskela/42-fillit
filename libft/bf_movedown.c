/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_movedown.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 02:08:21 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/30 18:00:15 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		bf_movedown_1(t_field *field)
{
	size_t		i;

	i = field->h - 1;
	while (i > 0)
	{
		field->row[i] = field->row[i - 1];
		field->row[i - 1] = 0;
		i--;
	}
}

void		bf_movedown(t_field *field, size_t steps)
{
	size_t		i;

	i = steps;
	if (!field || !field->row)
		return ;
	while (steps)
	{
		bf_movedown_1(field);
		steps--;
	}
	field->y += i;
}
