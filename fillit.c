/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 12:44:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/26 12:56:23 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"
#include "libft/libft.h"

int			main(void)
{

	size_t n = 0;
	size_t i = 0;
	uint64_t			*field = bf_init(8);

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

	while ((field[n] & piece[0]) > 0)
	{
		if (i == 6)
		{
			piece[0] = b("011");
			piece[1] = b("110");
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
	field[n] = field[n] | piece[0];
	field[n + 1] = field[n + 1] | piece[1];
	bf_print(field, 8);
	return (0);
}
