/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 02:46:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 01:54:48 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"

typedef struct		s_program
{
	char			*file;
	char			one;
	t_dlist			*blocks_ref;
	t_dlist			*input;
	t_dlist			*output;
	t_field			*board;
	size_t			steps;
	size_t			block_count;
}					t_program;

t_dlist			*read_input(char *file, char one);
int				val_blocks(t_dlist *input, t_dlist *ref);
int				val_input(char *file);
void			normalize_block(t_field *input);
void			solver(t_program *Program);
void			render_output(t_program *Program);

#endif
