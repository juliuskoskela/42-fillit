/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:55:17 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/29 04:37:18 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_program	program;
	size_t		init_size;

	program.blocks_ref = ref_blocks_list(0);
	program.input = read_input(argv[1], '#', 0);
	program.output = NULL;
	program.tet = NULL;
	program.block_count = dl_len(program.input);
	program.board = bf_new(16, 16);
	init_size = (size_t)ft_sqrt(program.block_count * 4);
	program.board->h = init_size;
	program.board->w = init_size;
	if (program.block_count > 26)
		error("error\n");
	if (argc != 2)
		error("usage: fillit input_file\n");
	if (!(val_blocks(program.input, program.blocks_ref)))
		error("error\n");
	solver(&program);
	bf_del(program.board);
	exit(0);
	return (0);
}
