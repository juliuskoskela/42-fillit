/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_moveup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 00:39:30 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/15 01:52:29 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void		bf_moveup(t_field **field, size_t steps)
{
	size_t		i;

	i = 0;
	if (!(*field))
		return ;
	while (steps)
	{
		while (i < (*field)->h)
		{
			(*field)->row[i] = (*field)->row[i + 1];
			(*field)->row[i + 1] = 0;
			i++;
		}
		i = 0;
		steps--;
	}
}
