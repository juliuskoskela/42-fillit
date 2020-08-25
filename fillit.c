/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 20:28:45 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/25 19:57:47 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"
#include "libft/libft.h"

int			main(void)
{
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
	return (0);
}
