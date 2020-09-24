/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_del_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:06:51 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/25 00:27:36 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		dl_del_last(t_dlist **ref)
{
	t_dlist	*current;

	if (*ref == NULL)
		return ;
	current = *ref;
	while (current->next)
		current = current->next;
	dl_del_node(ref, current);
}
