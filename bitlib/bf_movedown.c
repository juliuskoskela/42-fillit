/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_movedown.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 02:08:21 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/09 05:54:34 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void		bf_movedown(t_field **field, size_t steps)
{
	t_field		*tmp;
	size_t		i;

	tmp = bf_new((*field)->w, (*field)->h);
	i = 0;
	while (i < steps)
	{
		tmp->row[i] = 0;
		i++;
	}
	while (i < (*field)->h)
	{
		tmp->row[i] = (*field)->row[i - steps];
		i++;
	}
	bf_del(field);
	*field = tmp;
}
