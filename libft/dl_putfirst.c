/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_putfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:00:00 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 01:51:32 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		dl_putfirst(t_dlist **ref, void *new)
{
	t_dlist		*new_node;

	new_node = (t_dlist *)malloc(sizeof(t_dlist));
	new_node->content = new;
	new_node->next = (*ref);
	new_node->prev = NULL;
	if ((*ref) != NULL)
		(*ref)->prev = new_node;
	(*ref) = new_node;
}
