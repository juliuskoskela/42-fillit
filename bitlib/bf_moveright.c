/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_moveright.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 05:50:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/20 23:08:33 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void		bf_moveright(t_field *field, size_t steps)
{
	size_t		i;

	i = 0;
	if (!field || !field->row)
		return ;
	while (i < field->h)
	{
		field->row[i] = field->row[i] << steps;
		i++;
	}
	field->x += steps;
}
