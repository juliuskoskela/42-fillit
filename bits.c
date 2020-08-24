/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   bits.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jkoskela <jkoskela@student.hive.fi>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/08/22 00:04:12 by jkoskela		  #+#	#+#			 */
/*   Updated: 2020/08/24 00:38:32 by jkoskela		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft/libft.h"

uint			readbits(char *str, char c, int size)
{
	size_t		i;
	uint		nb;

	i = 0;
	nb = 0;
	while (i < size)
	{
		if (str[i] == c)
			nb |= 1 << i;
		if (str[i] != '\n')
			i++;
	}
	return (nb);
}

uint			checkbit(uint nb, int n)
{
	return ((nb >> n) & 1);
}

void			printbits(uint nb, int n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(checkbit(nb, i) ? '1' : '0');
		i++;
	}
}

uint			*bf_init(size_t size)
{
	size_t		i;
	uint		*field;

	i = 0;
	field = (uint *)malloc(sizeof(uint) * size);
	while (i < size - 1)
		field[i++] = 0;
	return (field);
}

void			bf_print(uint *field, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size)
	{
		printbits(field[i], size);
		ft_putchar('\n');
		i++;
	}
}

int				bf_fill(uint *field, char *file, char one, size_t size)
{
	char		*line;
	int			r;
	int			fd;
	size_t		i;

	fd = open(file, O_RDONLY);
	i = 0;
	while ((r = ft_gnl(fd, &line)) > 0)
	{
		if (line[0])
		{
			field[i] = readbits(line, one, size);
			free(line);
			i++;
		}
	}
	return(1);
}

void			bf_ynormal(uint *field, size_t size)
{
	size_t		i;

	i = 0;
	while (field[0] == 0)
	{
		while (i < size - 1)
		{
			field[i] = field[i  + 1];
			i++;
		}
		i = 0;
	}
	field[size - 1] = 0;
}

uint			bf_column(uint *field, size_t row, size_t size)
{
	uint		d;
	size_t		i;

	i = 0;
	d = 0;
	while (i < size - 1)
	{
		if (checkbit(field[i], 0) == 1)
			d |= 1 << i;
		i++;
	}
	return (d);
}

void			bf_moveleft(uint *field, size_t steps, size_t size)
{
	size_t		i;

	i = 0;
	while (i < size - 1)
	{
		field[i] = field[i] >> steps;
		i++;
	}
}

void			bf_xnormal(uint *field, size_t size)
{
	size_t		i;
	uint		d;

	i = 0;
	while ((d = bf_column(field, 0, size)) == 0 && i < size)
	{
		bf_moveleft(field, 1, size);
		i++;
	}
}

void			bf_normalize(uint *field, size_t size)
{
	bf_ynormal(field, size);
	bf_xnormal(field, size);
}

int				highest_one(uint nb, size_t size)
{
	size_t		i;
	int			r;

	i = 31;
	while (i > 0)
	{
		if (((nb >> i) & 1) == 1)
			return(i);
		i--;
	}
	return(0);
}

int				lowest_one(uint nb, size_t size)
{
	size_t		i;

	i = 0;
	while (i <= 31)
	{
		if (((nb >> i) & 1) == 1)
			return (i);
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	uint		*field;
	size_t		size;

	if (argc == 0)
		return (0);
	size = ft_atoi(argv[2]);
	field = bf_init(size);
	bf_fill(field, argv[1], '#', size);
	//bf_normalize(field, size);
	bf_print(field, size);
	printf("\n%u", field[0]);
	printf("\n%u", highest_one(field[0], size));
	printf("\n%u", lowest_one(field[0], size));
	printf("\n%lu", sizeof(field[0]));
	free(field);
	return (0);
}
