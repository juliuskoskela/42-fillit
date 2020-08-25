/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_xnormal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:07:34 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 20:18:00 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void			bf_xnormal(uint64_t *field, size_t size)
{
	size_t		i;
	uint64_t	d;

	i = 0;
	while ((d = bf_column(field, 0, size)) == 0 && i < size)
	{
		bf_moveleft(field, 1, size);
		i++;
	}
}