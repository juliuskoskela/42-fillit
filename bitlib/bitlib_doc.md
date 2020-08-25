# Bitlib

Library for bitfield manipulation in c.

By:
Julius Koskela
Aleksi Sukava

2020

## Synopsis

A library of useful functions for manipulating bits and bit-fields.

## Functions

```c
uint64_t		b(char *str);
uint64_t		readbits(char *str, char c, size_t size);
uint64_t		checkbit(uint64_t nb, int n);
void			printbits(uint64_t nb, size_t size);
uint64_t		*bf_init(size_t size);
void			bf_print(uint64_t *field, size_t size);
int 			bf_fill(uint64_t *field, char *file, char one, size_t size);
void			bf_ynormal(uint64_t *field, size_t size);
uint64_t		bf_column(uint64_t *field, size_t col, size_t size);
void			bf_moveleft(uint64_t *field, size_t steps, size_t size);
void			bf_xnormal(uint64_t *field, size_t size);
void			bf_normalize(uint64_t *field, size_t size);
size_t			highest_one(uint64_t nb, size_t size);
size_t			lowest_one(uint64_t nb, size_t size);
```

## Explanations

#### uint64_t		b(char *str);

Convert char string to unsigned 64 bit integer.

#### uint64_t		readbits(char *str, char c, size_t size);

Read a string as bits. Character c repersents 1. All other characters are viewed as 0.

#### uint64_t		checkbit(uint64_t nb, size_t pos);

Check bit in number nb at position pos.

#### void			printbits(uint64_t nb, size_t size);

Print size amount of bits from nb.

#### uint64_t		*bf_init(size_t size);

Initialize a bit field of size x size dimensions.

#### void			bf_print(uint64_t *field, size_t size);

Print a bit field of size dimensions.

#### int			bf_fill(uint64_t *field, char *file, char one, size_t size);

Fill a bit-field of size x size dimensions from a file. Char one denotes 1, all other characters (instead of \n) are read as 0. Newline separates rows.

#### void			bf_ynormal(uint64_t *field, size_t size);

Normalize field in y axis. This means all bits are moved to the top.

#### uint64_t		bf_column(uint64_t *field, size_t col, size_t size);

Normalize field in y axis. This means all bits are moved to the top.

#### void			bf_moveleft(uint64_t *field, size_t steps, size_t size);
#### void			bf_xnormal(uint64_t *field, size_t size);
#### void			bf_normalize(uint64_t *field, size_t size);
#### size_t			highest_one(uint64_t nb, size_t size);
#### size_t			lowest_one(uint64_t nb, size_t size);