/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:59:51 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/21 17:28:08 by jkoskela         ###   ########.fr       */
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

int			main(int argc, char **argv)
{
	char		*line;
	int			fd;
	int			r;
	int			nb[5][4];
	size_t		i;
	size_t		j;

	if (argc == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	i = 0;
	j = 0;
	while ((r = ft_gnl(fd, &line)) > 0)
	{
		if (line[0])
		{
			nb[j][i] = readbits(line, '#', 4);
			free(line);
			i++;
		}
		else
			j++;
	}
	while (j)
	{
		while (i)
		{
			printbits(nb[j][i],4);
			ft_putchar('\n');
			i--;
		}
		j--;
	}
	if (r == -1)
		printf("Error!");
	close(fd);
	return (0);
}
