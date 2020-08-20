/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:59:51 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/20 13:32:13 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int			main(int argc, char **argv)
{
	char		*line;
	int			fd;
	int			r;
	int			i;
	int			nb;

	if (argc == 0)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while ((r = ft_gnl(fd, &line)) > 0)
	{
		nb = ft_atoi_base(ft_strrev(line), 2);
		printf("%s\n%llu\n", line, nb);
		free(line);
	}
	if (r == -1)
		printf("Error!");
	close(fd);
	return (0);
}

//	Validate and store input from fd.

//		Read input until empty line.
//			Check that input is 4x4.
//			Check tetrimino shape.
//			Increment tetrimino[x] count.
//		If read > 0 repeat previous.
//	Create smallest possible field (longest side of pieces) and try blocks with smaller sides recursively.
//	If all blockes failed to fit in any config, increase x, y of field by 1 and go back to previous step.
//	Else print output.
