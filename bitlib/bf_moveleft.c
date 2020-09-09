/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_moveleft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:03:50 by esukava           #+#    #+#             */
/*   Updated: 2020/09/09 05:57:48 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void		bf_moveleft(t_field *field, size_t steps)
{
	size_t		i;

	i = 0;
	while (i < field->w)
	{
		field->row[i] = field->row[i] >> steps;
		i++;
	}
}
