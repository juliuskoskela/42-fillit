/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 01:51:48 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 01:51:52 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dl_rotate(t_dlist **head_ref, size_t N)
{
	t_dlist		*current;
	t_dlist		*NthNode;
	size_t		count;
	if (N == 0)
		return ;
	current = *head_ref;
	count = 1;
	while (count < N && current != NULL)
	{
		current = current->next;
		count++;
	}
	if (current == NULL)
		return ;
	NthNode = current;
	while (current->next != NULL)
		current = current->next;
	current->next = *head_ref;
	(*head_ref)->prev = current;
	*head_ref = NthNode->next;
	(*head_ref)->prev = NULL;
	NthNode->next = NULL;
}
