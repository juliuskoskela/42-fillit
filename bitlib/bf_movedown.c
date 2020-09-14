/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_movedown.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 02:08:21 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/14 03:43:57 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void		bf_movedown(t_field *field)
{
	size_t		i;

	i = field->h;
	while (i > 0)
	{
		field->row[i] = field->row[i - 1];
		field->row[i - 1] = 0;
		i--;
	}
}
