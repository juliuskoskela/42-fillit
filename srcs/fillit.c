/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:55:17 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/17 00:30:33 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_program	*Program = (t_program *)malloc(sizeof(t_program));

	Program->file = ft_strdup(argv[1]);
	Program->one = '#';
	Program->blocks_ref = read_input("txt/tetrominoes.txt", Program->one);
	Program->input = read_input(Program->file, Program->one);
	Program->output = NULL;
	Program->block_count = dl_len(Program->input);
	Program->board = bf_new((size_t)ft_sqrt(Program->block_count * 4), (size_t)ft_sqrt(Program->block_count * 4));
	Program->steps = 0;

	if (Program->block_count > 26)
		ERROR("\e[1;35mToo many blocks!\e[0m");
	if (argc != 2)
		ERROR("\e[1;35mToo many arguments!\e[0m");
	printf("\e\n[1;35mYou have %d blocks\n\n\e[0m", (int)Program->block_count);
	if (!(val_input(Program->file)))
		ERROR("\e[1;35minput incorrect!\e[0m");
	else
		printf("\e[1;35minput correct!\n\n\e[0m");
	if (!(val_blocks(Program->input, Program->blocks_ref)))
		ERROR("\e[1;35minput incorrect!\n\\ne[0m");
	else
		printf("\e[1;35mBlocks are valid!\n\e[0m");
	//field_list_print(Program->input);
	solver(Program);
	return (0);
}
