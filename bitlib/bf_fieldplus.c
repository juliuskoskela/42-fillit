/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_fieldplus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 05:55:31 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/09 05:55:45 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void		bf_fieldplus(t_field *board, t_field *field)
{
	size_t	i;

	i = 0;
	while (i < field->h)
	{
		board->row[i] = board->row[i] + field->row[i];
		i++;
	}
}