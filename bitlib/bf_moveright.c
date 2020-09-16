/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_moveright.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 05:50:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/16 19:26:31 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void		bf_moveright(t_field *field, size_t steps)
{
	size_t		i;

	i = 0;
	if (!field || !field->row)
		return ;
	while (i < field->w - 1)
	{
		field->row[i] = field->row[i] << steps;
		i++;
	}
}
