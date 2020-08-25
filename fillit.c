/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 20:28:45 by jkoskela          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/08/25 19:57:47 by esukava          ###   ########.fr       */
=======
/*   Updated: 2020/08/25 16:32:44 by jkoskela         ###   ########.fr       */
>>>>>>> 46c14b5f186929cf409bc22b55c1815f0fba45bf
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"
#include "libft/libft.h"

int			main(void)
{
<<<<<<< HEAD
	uint64_t			*field = bf_init(8);

							field[0] = b("11111110");
							field[1] = b("10000000");
							field[2] = b("00000000");
							field[3] = b("00000000");
							field[4] = b("00000000");
							field[5] = b("00000000");
							field[6] = b("00000000");
							field[7] = b("00000000");

	uint64_t			*piece = bf_init(2);
							
							piece[0] = b("11");
							piece[1] = b("11");

	solver(field, piece);
	ft_putchar('\n');
	printbits(bf_column(field, 2, 32), 32);
	ft_putchar('\n');
	printf("%llu\n", bf_column(field, 2, 32));
=======
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
>>>>>>> 46c14b5f186929cf409bc22b55c1815f0fba45bf
	return (0);
}
