/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testxy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 23:43:17 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/15 02:34:35 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"
#include <stdio.h>
// t_field				*movex(t_field *board, t_field *tetromino)
// {
// 	bf_moveright(&tetromino, 1);
// 	if (bf_overlap(&board, &tetromino))
// 		return(tetromino);
// 	bf_moveleft(&tetromino, 1);
// 	return (NULL);
// }

// t_field				*movey(t_field **board, t_field **tetromino)
// {
// 	bf_movedown(tetromino, 1);
// 	if (bf_overlap(board, tetromino))
// 		return(*tetromino);
// 	bf_moveup(tetromino, 1);
// 	return (NULL);
// }

int				movey(t_field *board, t_field *tetromino)
{
	bf_movedown(&tetromino, 1);
	if ((bf_overlap(&board, &tetromino)))
		return(1);
	bf_moveup(&tetromino, 1);
	return (0);
}

int		main(void)
{
	t_field		*f1 = bf_new(4, 4);
	f1->row[0] = b("0000");
	f1->row[1] = b("0110");
	f1->row[2] = b("0110");
	f1->row[3] = b("0000");

	t_field		*f2 = bf_new(4, 4);
	f2->row[0] = b("0000");
	f2->row[1] = b("0000");
	f2->row[2] = b("0000");
	f2->row[3] = b("0000");
	bf_moveup(&f1, 1);
	bf_movedown(&f1, 1);
	printf("\nret overlap: %d", bf_overlap(&f1, &f2));
	movey(f1, f2);
	bf_print(&f1);
	bf_del(&f1);
	return (0);
}
