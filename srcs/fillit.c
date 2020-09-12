/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:55:17 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/12 18:50:50 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_program	*PROGRAM = (t_program *)malloc(sizeof(t_program));

	PROGRAM->FILE = ft_strdup(argv[1]);
	PROGRAM->ONE = '#';
	PROGRAM->BLOCKS_REF = read_input("txt/tetrominoes.txt", PROGRAM->ONE);
	PROGRAM->INPUT = read_input(PROGRAM->FILE, PROGRAM->ONE);
	PROGRAM->BLOCK_COUNT = dl_len(PROGRAM->INPUT);
	PROGRAM->BOARD = bf_new((int)ft_sqrt(PROGRAM->BLOCK_COUNT * 4) - 1, (int)ft_sqrt(PROGRAM->BLOCK_COUNT * 4) - 1);

	if (PROGRAM->BLOCK_COUNT > 26)
		ERROR("\e[1;35mToo many blocks!\e[0m");
	if (argc != 2)
		ERROR("\e[1;35mToo many arguments!\e[0m");
	printf("\e\n[1;35mYou have %d blocks\n\n\e[0m", (int)PROGRAM->BLOCK_COUNT);
	if (!(val_input(PROGRAM->FILE)))
		ERROR("\e[1;35mSun inputti on ihan vituillaan!!\e[0m");
	else
		printf("\e[1;35mInput correct!\n\n\e[0m");
	if (!(val_blocks(PROGRAM->INPUT, PROGRAM->BLOCKS_REF)))
		ERROR("\e[1;35mInput incorrect!\n\\ne[0m");
	else
		printf("\e[1;35mBlocks are valid!\n\e[0m");
	//field_list_print(PROGRAM->INPUT);
	solver(PROGRAM, PROGRAM->INPUT, NULL, 0);
	return (0);
}
