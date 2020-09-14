/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_overlap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 05:59:29 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/15 01:53:21 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

int			bf_overlap(t_field **board, t_field **field)
{
	size_t	i;

	i = 0;
	if (!(*board) || !(*field))
		return (-1);
	while (i < (*field)->h)
	{
		if (((*board)->row[i] & (*field)->row[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}
