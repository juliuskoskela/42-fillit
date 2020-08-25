/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 20:28:45 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/25 16:32:44 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"
#include "libft/libft.h"

int			main(void)
{
	uint64_t		*field;
	uint64_t		t;

	field = bf_init(8);
	field[0] = b("11110000");
	field[1] = b("00000000");
	field[2] = b("00000000");
	field[3] = b("00000000");
	field[4] = b("00000000");
	field[5] = b("00000000");
	field[6] = b("00000000");
	field[7] = b("00000000");

	t = b("1110");
	while ((t & field[0]) > 0)
		t = t << 1;
	field[0] = t | field[0];
	bf_print(field, 8);
	return (0);
}
