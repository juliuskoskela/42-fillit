/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:51:08 by esukava           #+#    #+#             */
/*   Updated: 2020/09/20 23:18:03 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

static void		ft_putchar(char c)
{
	write(1, &c, 1);
}

static void		ft_putnbr(uint64_t n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

static void			bf_print1(uint64_t *field, size_t w, size_t h)
{
	size_t		i;

	i = 0;
	while (i < h)
	{
		printbits(field[i], w * 2);
		write(1, ":", 1);
		ft_putnbr(field[i]);
		write(1, "\n", 1);
		i++;
	}
}

void			bf_print(t_field *field)
{
	if (!field)
		return ;
	bf_print1(field->row, field->w, field->h);
}
