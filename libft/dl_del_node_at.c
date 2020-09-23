/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_del_node_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:06:51 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 01:51:11 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		dl_del_node_at(t_dlist **ref, size_t pos)
{
	t_dlist	*current;
	size_t		i;

	if (*ref == NULL || pos <= 0)
		return ;
	current = *ref;
	i = 1;
	while (current != NULL && i < pos)
	{
		current = current->next;
		i++;
	}
	if (current == NULL)
		return ;
	dl_del_node(ref, current);
}
