/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c	                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:10:54 by esukava           #+#    #+#             */
/*   Updated: 2020/08/25 19:54:15 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"
#include "../libft/libft.h"

uint64_t		solver(uint64_t *field, uint64_t *piece)
{
	int n = 0;
	int i = 0;
	while ((field[n] & piece[0]) > 0)
	{
		if (i == 6)
		{
			piece[0] = b("11");
			piece[1] = b("11");
			n++;
			i = 0;
		}
		else
		{
			piece[0] = piece[0] << 1;
			piece[1] = piece[1] << 1;
			i++;
		}
	}
	field[n] 	 = field[n]		| piece[0];
	field[n + 1] = field[n + 1] | piece[1];
	bf_print(field, 8);
	return (0);
}
