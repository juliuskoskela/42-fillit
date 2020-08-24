/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 20:28:45 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/24 23:42:14 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"
#include <stdio.h>

int			main(void)
{
	int		x = 8;
	printbits(x, 4);
	printf("\n%d", (int)highest_one(x, 4));
	return (0);
}
