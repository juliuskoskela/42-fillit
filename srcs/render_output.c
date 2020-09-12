/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   render_output.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jkoskela <jkoskela@student.hive.fi>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/09/09 05:30:06 by jkoskela		  #+#	#+#			 */
/*   Updated: 2020/09/12 18:23:01 by jkoskela		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "fillit.h"

char		*bitoa(uint64_t nb, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	str = ft_strnew(len);
	str[len + 1] = '\0';
	while (i < len)
	{
		if (checkbit(nb, i) == 1)
			str[i] = '1';
		else
			str[i] = '0';
		i++;
	}
	return (str);
}

void		render_line(char *dest, char *src, char c)
{
	size_t		i;

	i = 0;

	while (dest[i] != '\0')
	{
		if (src[i] == '1')
			dest[i] = c;
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
	array = (char **)malloc(sizeof(char) *  size + 1);
	printf("\nOutput list at exit:\n\n");
	field_list_print(output);
	bcnt = dl_len(output);
	printf("\e\n[1;34mStart board xy: %d\n\n\e[0m", (int)ft_sqrt(PROGRAM->BLOCK_COUNT * 4) - 1);
	printf("\e[1;34mOutput count at exit: %zu\n\e[0m", bcnt);
	printf("\e[1;34m\nBoard at exit(size %zu):\n\n\e[0m", PROGRAM->BOARD->w);
	printf("board: \n\n");
	bf_print(PROGRAM->BOARD);
	printf("\n");
	printf("output render: \n\n");
	while (i < size)
	{
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
	while (i < PROGRAM->BLOCK_COUNT)
	{
		tmp = output->content;
		render(tmp, array, c);
		if (output->next)
			output = output->next;
		i++;
		c++;
	}
	i = 0;
	while (i < size)
	{
		ft_putstr(array[i]);
		i++;
	}
}
