/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libdl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 02:46:16 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/29 00:25:46 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBDL_H
# define LIBDL_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include "../bitlib/bitlib.h"

typedef struct		s_field
{
	uint64_t		*row;
	size_t			w;
	size_t			h;
}					t_field;

typedef struct		s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

size_t		dl_len(t_dlist *node);
void		dl_putfirst(t_dlist **ref, void *new);
void		dl_putlast(t_dlist **ref, void *new);
void		dl_putbefore(t_dlist **ref, t_dlist *next, void *new);
void		dl_putafter(t_dlist **ref, t_dlist *prev, void *new);
void		dl_print(t_dlist *node);
void		dl_print_b(t_dlist *node);
void		dl_del_node(t_dlist **ref, t_dlist *del);
void		dl_del_node_at(t_dlist **ref, size_t pos);

#endif
