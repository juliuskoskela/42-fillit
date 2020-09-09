# Bitlib

Library for bitfield manipulation in c.

By:
Julius Koskela
Aleksi Sukava

2020

## Synopsis

A library of useful functions for manipulating bits and bit-fields.

## Functions and Structs

```c
typedef struct		s_field
{
	uint64_t		*row;
	size_t			w;
	size_t			h;
}					t_field;

uint64_t		b(char *str);
uint64_t		readbits(char *str, char c, size_t size);
uint64_t		checkbit(uint64_t nb, int n);
void			printbits(uint64_t nb, size_t size);
uint64_t		*bf_init(size_t size);
void			bf_print(t_field *field);
int				bf_fill(uint64_t *field, char *file, char one, size_t size);
uint64_t		bf_column(uint64_t *field, size_t col, size_t size);
void			bf_moveleft(t_field *field, size_t steps);
void			bf_moveright(t_field *field, size_t steps);
void			bf_movedown(t_field **field, size_t steps);
size_t			highest_one(uint64_t nb, size_t size);
size_t			lowest_one(uint64_t nb, size_t size);
int				bf_cmp(t_field *f1, t_field *f2);
t_field			*bf_new(size_t w, size_t h);
void			bf_fieldsize(t_field *field);
void			bf_del(t_field **field);
void			bf_fieldplus(t_field *board, t_field *field);
void			bf_fieldminus(t_field *board, t_field *field);
int				bf_overlap(t_field *board, t_field *field);
```

## Explanations

#### b

Convert char string to unsigned 64 bit integer.

#### readbits

Read a string as bits. Character c repersents 1. All other characters are viewed as 0.

#### checkbit

Check bit in number nb at position pos.

#### printbits

Print size amount of bits from nb.

#### bf_init

Initialize a bit field of size x size dimensions.

#### bf_print

Print a bit field.

#### bf_fill

Fill a bit-field of size x size dimensions from a file. Char one denotes 1, all other characters (instead of \n) are read as 0. Newline separates rows.


#### bf_column

Normalize field in y axis. This means all bits are moved to the top.

#### bf_moveleft

Move bits to the left of the field.

#### bf_xnormal

Normalize field in x axis. This means all bits are moved to the left.

#### bf_normalize

Normalize field in x and y axis. Bits are moved to top left.

#### highest_one

Find the position of the highest 1 bit.

#### lowest_one

Find the position of the lowest 1 bit.