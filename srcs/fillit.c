
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:55:17 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/29 21:14:51 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_program	*PROGRAM = (t_program *)malloc(sizeof(t_program));

	PROGRAM->FILE = ft_strdup(argv[1]);
	PROGRAM->ONE = '#';
	PROGRAM->BOARD = bf_new(2, 2);
	PROGRAM->BLOCKS_REF = read_input("txt/tetrominoes.txt", PROGRAM->ONE);
	PROGRAM->INPUT = read_input(PROGRAM->FILE, PROGRAM->ONE);
	PROGRAM->BLOCK_COUNT = dl_len(PROGRAM->INPUT);

	printf("Sul on %d palikkaa.\n", (int)PROGRAM->BLOCK_COUNT);
	if (!(val_input(PROGRAM->FILE)))
	{
		printf("Sun inputti on ihan vituillaan!\n");
		return (0);
	}
	else
		printf("Sun inputit on tikis!.\n");
	if (!(val_blocks(PROGRAM->INPUT, PROGRAM->BLOCKS_REF)))
	{
		printf("Ei nää oo tetrispalikoit, urpo!\n");
		return (0);
	}
	else
		printf("... ja palikatki mintis!\n");
	argc = 0;
	return (0);
}
