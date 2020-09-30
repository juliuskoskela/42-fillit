/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 02:46:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/29 04:37:39 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"

typedef struct		s_program
{
	t_dlist			*blocks_ref;
	t_dlist			*input;
	t_dlist			*output;
	t_field			*board;
	t_field			*tet;
	size_t			block_count;
}					t_program;

t_dlist				*read_input(char *file, char one, size_t i);
int					val_blocks(t_dlist *input, t_dlist *ref);
void				normalize_block(t_field *input);
void				solver(t_program *program);
void				render_output(t_program *program);
t_dlist				*ref_blocks_list();

#endif
