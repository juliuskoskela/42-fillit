/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printbits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:44:16 by esukava           #+#    #+#             */
/*   Updated: 2020/08/24 14:45:00 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

void			printbits(uint nb, int n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(checkbit(nb, i) ? '1' : '0');
		i++;
	}
}
