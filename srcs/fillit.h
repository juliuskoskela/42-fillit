/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 02:46:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/30 00:38:09 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../bitlib/bitlib.h"
# include "../libft/libft.h"
# include "../libdl/libdl.h"

typedef struct		s_program
{
	char			*FILE;
	char			ONE;
	t_dlist			*BLOCKS_REF;
	t_dlist			*INPUT;
	t_field			*BOARD;
	size_t			BLOCK_COUNT;
}					t_program;

t_dlist			*read_input(char *file, char one);
int				val_blocks(t_dlist *input, t_dlist *ref);
int				val_input(char *file);

#endif
