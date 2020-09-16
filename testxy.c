/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testxy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 23:43:17 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/16 16:30:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"
#include "libft/libft.h"
#include <stdio.h>

int		main(void)
{
	int			ret;
	t_field 	*tmp;
	t_field		*f1 = bf_new(4, 4);
	f1->row[0] = b("0110");
	f1->row[1] = b("0110");
	f1->row[2] = b("0000");
	f1->row[3] = b("0000");

	t_field		*f2 = bf_new(4, 4);
	f2->row[0] = b("0000");
	f2->row[1] = b("0000");
	f2->row[2] = b("0000");
	f2->row[3] = b("0000");

	bf_moveright(f1, 1);
	bf_moveleft(f1, 1);
	bf_movedown(f1, 2);
	bf_moveup(f1, 1);
	ret = bf_overlap(f1, f2);
	printf("\n");
	ft_putnbr(ret);
	printf("\n");
	bf_print(f1);
	printf("\n");
	bf_print(f2);
	bf_del(f1);
	return (0);
}
