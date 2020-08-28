/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 02:25:30 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/28 15:22:06 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"
#include <stdio.h>

typedef struct		s_field
{
	uint64_t		*row;
	int				w;
	int				h;
}					t_field;

typedef struct		s_dlist
{
	t_field			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

size_t		dl_len(t_dlist *node)
{
	t_dlist		*tmp;
	size_t		count;

	tmp = node;
	count = 0;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void		dl_putfirst(t_dlist **ref, t_field *new)
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

void		dl_putlast(t_dlist **ref, t_field *new)
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

void		dl_putbefore(t_dlist **ref, t_dlist *next, t_field *new)
{
	t_dlist	*new_node;

	if (next == NULL)
		return ;
	new_node = (t_dlist *)malloc(sizeof(t_dlist));
	new_node->content = new;
	new_node->prev = next->prev;
	next->prev = new_node;
	new_node->next = next;
	if (new_node->prev != NULL)
		new_node->prev->next = new_node;
	else
		(*ref) = new_node;
}

void		dl_putafter(t_dlist **ref, t_dlist *prev, t_field *new)
{
	t_dlist	*new_node;

	if (prev == NULL)
		return ;
	new_node = (t_dlist *)malloc(sizeof(t_dlist));
	new_node->content = new;
	new_node->next = prev->next;
	prev->next = new_node;
	new_node->prev = prev;
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
	else
		(*ref) = new_node;
}

void		dl_print(t_dlist *node)
{
	t_dlist	*last;

	while (node != NULL)
	{
		bf_print(node->content->row, node->content->w, node->content->h);
		printf("\n");
		last = node;
		node = node->next;
	}
}

void		dl_print_b(t_dlist *node)
{
	t_dlist	*last;

	while (last != NULL)
	{
		bf_print(last->content->row, last->content->w, node->content->h);
		printf("\n");
		last = last->prev;
	}
}

void		dl_del_node(t_dlist **ref, t_dlist *del)
{
	if (*ref == NULL || del == NULL)
		return ;
	if (*ref == del)
		*ref = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del);
}

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

int			main(void)
{
	t_dlist		*head = NULL;
	t_dlist		*tmp = NULL;
	t_field		*tet1 = (t_field *)malloc(sizeof(t_field));
				tet1->row = bf_init(4);
					tet1->row[0] = b("1");
					tet1->row[1] = b("1");
					tet1->row[2] = b("1");
					tet1->row[3] = b("1");
				tet1->h = 4;
				tet1->w = 1;
	t_field		*tet2 = (t_field *)malloc(sizeof(t_field));
				tet2->row = bf_init(4);
					tet2->row[0] = b("10");
					tet2->row[1] = b("10");
					tet2->row[2] = b("11");
				tet2->h = 3;
				tet2->w = 2;
	t_field		*tet3 = (t_field *)malloc(sizeof(t_field));
				tet3->row = bf_init(4);
					tet3->row[0] = b("110");
					tet3->row[1] = b("011");
				tet3->h = 2;
				tet3->w = 3;

	dl_putfirst(&head, tet3);
	dl_putlast(&head, tet1);
	dl_putlast(&head, tet2);
	dl_print(head);
	return (0);
}
