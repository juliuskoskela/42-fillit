/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_del_node_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:06:51 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/28 15:07:12 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdl.h"

void		dl_del_node_at(t_dlist **ref, int n)
{
	t_dlist	*current;
	int		i;

	if (*ref == NULL || n <= 0)
		return ;
	current = *ref;
	i = 1;
	while (current != NULL && i < n)
	{
		current = current->next;
		i++;
	}
	if (current == NULL)
		return ;
	dl_del_node(ref, current);
}
