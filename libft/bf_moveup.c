/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_moveup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 00:39:30 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 01:50:00 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		bf_moveup_1(t_field *field)
{
	size_t		i;

	i = 0;
	if (!field)
		return ;
	while (i < field->h - 1)
	{
		field->row[i] = field->row[i + 1];
		field->row[i + 1] = 0;
		i++;
	}
}

void		bf_moveup(t_field *field, size_t steps)
{
	while (steps)
	{
		bf_moveup_1(field);
		steps--;
	}
	field->y -= steps;
}
