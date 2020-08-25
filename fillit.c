/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 20:28:45 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/25 02:06:50 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"
#include "libft/libft.h"

uint64_t		b(char *str)
{
	size_t		i;
	size_t		size;
	uint64_t	nb;

	i = 0;
	nb = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		if (str[i] == '1')
			nb |= 1 << i;
		if (str[i] != '1' && str[i] != '0')
			return (0);
		i++;
	}
	return (nb);
}

int			main(void)
{
	uint64_t				*field = bf_init(32);

							field[6] = b("00100000000000000000000000000000");
	bf_print(field, 32);
	ft_putchar('\n');
	printbits(bf_column(field, 2, 32), 32);
	return (0);
}
