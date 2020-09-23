/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_putlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 15:00:35 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 01:51:37 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		dl_putlast(t_dlist **ref, void *new)
{
	t_dlist	*temp;
	t_dlist	*ptr;

	ptr = NULL;
	temp = (t_dlist *)malloc(sizeof(t_dlist));
	temp->content = new;
	temp->prev = NULL;
	temp->next = NULL;
	if (*ref == NULL)
		(*ref) = temp;
	else
	{
		ptr = (*ref);
		while (ptr->next != NULL)
			ptr = ptr->next;
		temp->prev = ptr;
		ptr->next = temp;
	}
}
