/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:10:40 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/28 02:17:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib/bitlib.h"

typedef struct	s_field
{
	uint64_t		*row;
	int				w;
	int				h;
}					t_field;

typedef struct	s_list
{
	t_field			*content;
	struct s_list	*next;
}					t_list;

uint64_t		*bf_init(size_t size)
{
	size_t		i;
	uint64_t	*field;

	i = 0;
	field = (uint64_t *)malloc(sizeof(uint64_t) * size);
	while (i < size - 1)
		field[i++] = 0;
	return (field);
}

t_list			*ft_newnode(t_field *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void			ft_lstadd(t_list **alst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}

void			ft_lstpushback(t_list *p, t_list *new)
{
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}

void			ft_printfields(t_list *p)
{
	while (p != NULL)
	{
		bf_print(p->content->row, p->content->w, p->content->h);
		p = p->next;
	}
}

t_field			*bf_copy(t_field *src)
{
	t_field		*dst;
	int			i;

	i = 0;
	dst = (t_field *)malloc(sizeof(t_field));
	dst->row = bf_init(src->h);
	dst->h = src->h;
	dst->w = src->w;
	while (i < src->h)
	{
		dst->row[i] = src->row[i];
		i++;
	}
	return (dst);
}

int				pushlast(t_list **head_ref)
{
	if (*head_ref == NULL || (*head_ref)->next == NULL)
		return (0);
	t_list *first = *head_ref;
	t_list *last = *head_ref;
	while (last->next != NULL)
		last = last->next;
	*head_ref = first->next;
	first->next = NULL;
	last->next = first;
	return (1);
}

int				fitblock(t_field *block, t_field *field, int field_offset, int x_offset, int y_offset)
{
	if (field->h - block->h <= 0)
		return (0);
	if ((block->row[y_offset] & field->row[field_offset]) == 0 && field_offset < field->h - block->h)
	{
		while (y_offset < block->h && (block->row[y_offset] & field->row[field_offset]) == 0)
			y_offset++;
		if (y_offset == block->h)
		{
			while (y_offset)
			{
				field->row[field_offset + y_offset] |= block->row[y_offset];
				y_offset--;
			}
			return (1);
		}
		while (y_offset < block->h)
		{
			block->row[y_offset] = block->row[y_offset] << 1;
			y_offset++;
		}
		y_offset = 0;
		x_offset++;
	}
	while ((block->row[y_offset] & field->row[field_offset]) != 0 && field_offset < field->h - block->h)
	{
		while (y_offset < block->h)
		{
			block->row[y_offset] = block->row[y_offset] << 1;
			y_offset++;
		}
		y_offset = 0;
		x_offset++;
	}
	if (field_offset == field->h - block->h)
		return (0);
	else
		return (fitblock(block, field, field_offset++, x_offset, 0));
}

int				test_blocks(t_field *field, t_list *blocks, int stop)
{
	int			r = 0;
	int			block_count = 3;
	t_field 	*tmp;
	t_list		*head = blocks;

	if(stop == block_count)
		return (0);
	while (blocks->next)
	{
		tmp = bf_copy(blocks->content);
		r = fitblock(blocks->content, field, 0, 0, 0);
		if (r == 1)
			blocks = blocks->next;
		else
		{
			blocks = head;
			head = head->next;
			r = pushlast(&blocks);
			test_blocks(field, head, stop + 1);
			break ;
		}
	}
	if (stop < block_count)
	{
		blocks = head;
		head = head->next;
		r = pushlast(&blocks);
		test_blocks(field, head, stop + 1);
	}
	return (1);
}

int		solver(t_list *blocks, int field_size)
{
	int			r;
	t_field		*field;

	field = (t_field *)malloc(sizeof(t_field));
	field->row = bf_init(field_size);
	field->h = field_size;
	field->w = field_size;
	r = test_blocks(field, blocks, 0);
	if (r == 0)
	{
		free(field->row);
		field->w++;
		field->h++;
		solver(blocks, field_size++);
	}
	bf_print(field->row, field_size, field_size);
	return (1);
}

int				main(void)
{
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
				tet3->w = 4;
	t_list		*tet_list;

	tet_list = ft_newnode(tet1);
	ft_lstpushback(tet_list, ft_newnode(tet2));
	ft_lstpushback(tet_list, ft_newnode(tet3));
	solver(tet_list, 2);
	//ft_printfields(tet_list);
	return (0);
}
