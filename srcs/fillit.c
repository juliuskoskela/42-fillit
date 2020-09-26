/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:55:17 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/26 16:47:07 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_program	program;

	program.one = '#';
	program.blocks_ref = read_input("tetrominoes.txt", program.one);
	program.input = read_input(argv[1], program.one);
	program.output = NULL;
	program.block_count = dl_len(program.input);
	program.board = bf_new((size_t)ft_sqrt(program.block_count * 4), \
							(size_t)ft_sqrt(program.block_count * 4));
	if (program.block_count > 26)
		error("error\n");
	if (argc != 2)
		error("usage: fillit input_file\n");
	if (!(val_blocks(program.input, program.blocks_ref)))
		error("error\n");
	solver(&program);
	exit(0);
	return (0);
}
