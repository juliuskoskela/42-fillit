/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 05:30:06 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/12 17:41:42 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*bitoa(uint64_t nb, size_t len)
{
	size_t		i;
	char		*str;
	
	i = 0;
	
//	printf("bitoa, lol");
	str = ft_strnew(len);
	str[len + 1] = '\0';
	while (i < len)
	{
		if (checkbit(nb, i) == 1)
		{
			str[i] = '1';
	//		write (1, "x", 1);
		}
		else
		{
			str[i] = '0';
	//		write (1, "y", 1);
		}
		i++;
	}

//	printf("str in bitoa is = %s", str);
	return (str);
}

void		render_line(char *dest, char *src, char c)
{
	size_t		i;

	i = 0;

	while (dest[i] != '\0')
	{
	//	write(1, "qq", 2);
		if (src[i] == '1')
		{
	//		write(1, "JOE", 3);
			dest[i] = c;
		}
		i++;
	}
}

void		render(t_field *field, char **array, char c)
{
	size_t		i;
	char		*tmp;

	i = 0;

	while (i < field->h)
	{
		tmp = bitoa(field->row[i], field->w);
		render_line(array[i], tmp, c);
		free(tmp);
		i++;
	}
}

void			render_output(t_program *PROGRAM, t_dlist *output)
{
	size_t		i;
	size_t		j;
	size_t		bcnt;
	size_t		size;
	char		c;
	t_field		*tmp;
	char		**array;

	i = 0;
	j = 0;
	size = PROGRAM->BOARD->h;
	c = 'A';
	array = (char **)malloc(sizeof(char) *  size);
	printf("\nOutput list at exit:\n\n");
//	field_list_print(output);
	bcnt = dl_len(output);
	printf("\e\n[1;38mStart board xy = %d\n\n\e[0m", (int)ft_sqrt(PROGRAM->BLOCK_COUNT * 4) - 1);
	printf("\e[1;38mOutput count at exit: %zu\n\e[0m", bcnt);
	printf("\e[1;38m\nBoard at exit(size %zu):\n\n\e[0m", PROGRAM->BOARD->w);
	printf("PROGRAM->BOARD = \n");
	bf_print(PROGRAM->BOARD);
	printf("\n");
	printf("output render = \n");
         while (i < size)
         {
//			write(1, "1", 1);
        	array[i] = ft_strnew(size + 2);
         	array[i][size] = '\n';
         	array[i][size + 1] = '\0';
         	while (j < size)
         	{
         		array[i][j] = '.';
         		j++;
         	}
         	j = 0;
         	i++;
         }
         i = 0;
		 while (i < PROGRAM->BLOCK_COUNT - 1) // -1 added to repair segfault
		{	
//			write(1, "2", 1);
			tmp = output->content;
         	render(tmp, array, c);
         	output = output->next;
         	i++;
			c++;
         }
		 write(1, "\n", 1);
         i = 0;
         while (i < size)
         {
			
//			write(1, "3", 1);
         	ft_putstr(array[i]);
         	i++;
         }
}
