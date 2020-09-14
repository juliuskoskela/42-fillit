/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:00:27 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/14 16:00:55 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void		bf_clear(t_field *field)
{
	size_t	i;

	i = 0;
	while (i < field->h)
	{
		field->row[i] = 0;
		i++;
	}
}
