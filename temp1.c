/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:59:51 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/21 19:17:42 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

unsigned int		readbits(char *str, char c, int bits)
{
	size_t			i;
	unsigned int	nb;

	i = 0;
	while (i < bits)
	{
		if (str[i] == c)
			nb |= 1UL << i; // Set bit at i:th index. i = 0
		if (str[i] != '\n')
			i++;
	}
	return (nb);
}

unsigned int		checkbit(unsigned int nb, int n)
{
	return ((nb >> n) & 1U); // Check n:th bit. i = 0
}

void				printbits(unsigned int nb, int n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(checkbit(nb, i) ? '1' : '0');
		i++;
	}
}

int			*ft_trunc_input(int *nb, size_t xy)
{
	size_t		i;
	size_t		j;
	int			*d;

	i = 0;
	j = 0;
	d = (int *)malloc(sizeof(int) * xy);
	// Check if empty lines above. If so remove.
	while (i < xy)
	{
		if (nb[i] == 0)
			i++;
		else
		{
			d[j] = nb[i];
			i++;
			j++;
		}
	}
	return (d);
	// Check if empty colums to the right. If so remove.
}

int			main(int argc, char **argv)
{
	char		*line;
	int			fd;
	int			r;
	int			nb[4];
	size_t		i;
	size_t		j;
	size_t		xy = 4;
	int			*d;

	if (argc == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while ((r = ft_gnl(fd, &line)) > 0)
	{
		if (line[0])
		{
			nb[i] = readbits(line, '#', 4);
			free(line);
			i++;
		}
	}
	j = 0;
	d = ft_trunc_input(nb, xy);
	while (j < xy)
	{
		printbits(d[j], 4);
		ft_putchar('\n');
		j++;
	}
	if (r == -1)
		printf("Error!");
	close(fd);
	return (0);
}
