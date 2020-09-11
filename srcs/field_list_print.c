/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_list_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 03:58:57 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/11 03:59:56 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		field_list_print(t_dlist *ref)
{
	t_field		*field;
	t_dlist		*tmp;

	tmp = ref;
	while (tmp)
	{
		field = tmp->content;
		bf_print(field);
		printf("\nf->h: %zu\n", field->h);
		printf("\nf->w: %zu\n", field->w);
		printf("\n");
		tmp = tmp->next;
	}
}
