

# Libdl - Doubly linked list implementation.

## Header definitions

Below are the header definitions for struct and functions in Libdl.

```c
typedef struct      s_dlist
{
	void            *content;
	struct s_dlist  *next;
	struct s_dlist  *prev;
}                   t_dlist;

size_t		dl_len(t_dlist *node);
void		dl_putfirst(t_dlist **ref, void *new);
void		dl_putlast(t_dlist **ref, void *new);
void		dl_putbefore(t_dlist **ref, t_dlist *next, void *new);
void		dl_putafter(t_dlist **ref, t_dlist *prev, void *new);
void		dl_print(t_dlist *node);
void		dl_print_b(t_dlist *node);
void		dl_del_node(t_dlist **ref, t_dlist *del);
void		dl_del_node_at(t_dlist **ref, size_t pos);
void		dl_del_last(t_dlist **ref);
void		dl_rotate(t_dlist **head_ref, size_t rots);
```

| Function		| Usage			|
| -------------	| -------------	|
| `size_t		dl_len(t_dlist *node);`	|Returns the length of the list from the head node in datatype size_t.	|
| `dl_putfirst`	| Puts node as the first node of the linked list. If list is empty, creates first node.	|
| `dl_putlast`	| Puts node as the last node of the linked list. If list is empty, creates first node.	|
| `dl_putbefore`		| Puts node before next node in the linked list. If list is empty, creates first node.	|
| `dl_putafter`		| Puts node after previous node in the linked list. If list is empty, creates first node.	|
| `dl_print`			| Content Cell	|
| `dl_print_b`		| Content Cell	|
| `dl_del_node`		| Content Cell	|
| `dl_del_node_at`	| Content Cell	|
| `dl_del_last`		| Content Cell	|
| `dl_rotate`			| Content Cell	|
| Content Cell		| Content Cell	|
| Content Cell		| Content Cell	|
| Content Cell		| Content Cell	|