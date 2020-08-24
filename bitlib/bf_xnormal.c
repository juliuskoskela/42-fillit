/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_xnormal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:07:34 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 16:48:04 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void			bf_xnormal(unsigned int *field, size_t size)
{
	size_t		i;
	unsigned int		d;

	i = 0;
	while ((d = bf_column(field, 0, size)) == 0 && i < size)
	{
		bf_moveleft(field, 1, size);
		i++;
	}
}
