// Check 1st piece to top left of field.
// If piece fits, try next piece.
// If piece doesn't fit go and change the previous piece.
// If all piece fit return 1.
// If can't go to previous piece, increase field size.

#include <stdio.h>
#include <stdlib.h>

// A linked list node
typedef struct	s_field
{
	uint64_t		*row;
	int				w;
	int				h;
}					t_field;

typedef struct	s_list
{
	t_field			*content;
	struct s_list 	*next;
	struct s_list 	*prev;
}					t_list;

/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void	inser_first(t_list **head_ref, t_field *new_content)
{
	t_list *new_node;

	new_node = (t_list*)malloc(sizeof(t_list));
	new_node->content = new_content;
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	(*head_ref) = new_node;
}

/* Given a node as next_node, insert a new node before the given node */
void	insert_before(t_list **head_ref, t_list *next_node, t_field *new_content)
{
	/*1. check if the given next_node is NULL */
	if (next_node == NULL)
		return ;
	/* 2. allocate new node */
	t_list* new_node = (t_list*)malloc(sizeof(t_list));
	/* 3. put in the content */
	new_node->content = new_content;
	/* 4. Make prev of new node as prev of next_node */
	new_node->prev = next_node->prev;
	/* 5. Make the prev of next_node as new_node */
	next_node->prev = new_node;
	/* 6. Make next_node as next of new_node */
	new_node->next = next_node;
	/* 7. Change next of new_node's previous node */
	if (new_node->prev != NULL)
		new_node->prev->next = new_node;
	/* 8. If the prev of new_node is NULL, it will be the new head node */
	else
		(*head_ref) = new_node;
}

// This function prints contents of linked list starting from the given node
void		print_list(t_list* node)
{
	t_list	*last;
	printf("\nTraversal in forward direction \n");
	while (node != NULL)
	{
		printf(" %d ", node->content);
		last = node;
		node = node->next;
	}
	printf("\nTraversal in reverse direction \n");
	while (last != NULL)
	{
		printf(" %d ", last->content);
		last = last->prev;
	}
}

/* Driver program to test above functions*/
int		main()
{
	/* Start with the empty list */
	t_list* head = NULL;
	push(&head, 7);

	push(&head, 1);

	push(&head, 4);

	// Insert 8, before 1. So linked list becomes 4->8->1->7->NULL
	insertBefore(&head, head->next, 8);

	printf("Created DLL is: ");
	printList(head);

	getchar();
	return 0;
}