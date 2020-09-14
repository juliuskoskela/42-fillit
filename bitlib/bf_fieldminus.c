/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_fieldminus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 05:57:18 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/15 01:51:49 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void		bf_fieldminus(t_field **board, t_field **field)
{
	size_t	i;

	i = 0;
	if (!(*field) || !(*board))
		return ;
	while (i < (*field)->h)
	{
		(*board)->row[i] = (*board)->row[i] - (*field)->row[i];
		i++;
	}
}
