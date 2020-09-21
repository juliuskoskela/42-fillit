/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 23:55:17 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/21 01:48:09 by jkoskela         ###   ########.fr       */
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
		ERROR("error\n");
	if (argc != 2)
		ERROR("FIX!");
	if (!(val_input(Program->file)))
		ERROR("error\n");
	if (!(val_blocks(Program->input, Program->blocks_ref)))
		ERROR("error\n");
	solver(Program);
	return (0);
}
