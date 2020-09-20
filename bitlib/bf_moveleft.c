/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_moveleft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:03:50 by esukava           #+#    #+#             */
/*   Updated: 2020/09/20 23:08:47 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void		bf_moveleft(t_field *field, size_t steps)
{
	size_t		i;

	i = 0;
	if (!field || !field->row)
		return ;
	while (i < field->h)
	{
		field->row[i] = field->row[i] >> steps;
		i++;
	}
	field->x -= steps;
}
