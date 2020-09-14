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
	write(1, "render:\n\n", 9);
	while (i < field->h)
	{
		tmp = bitoa(field->row[i], field->w);
		render_line(array[i], tmp, c);
		free(tmp);
		i++;
	}
}

void			render_output(t_program *Program)
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
	size = Program->board->h;
	c = 'A';
	array = (char **)malloc(sizeof(char) *  size + 1);
	// printf("\noutput list at exit:\n\n");
	while (Program->output->prev)
		Program->output = Program->output->prev;
	field_list_print(Program->output);
	bcnt = dl_len(Program->output);
	printf("len: %ld\n", bcnt);
	// // printf("\e\n[1;34mStart board xy: %d\n\n\e[0m", (int)ft_sqrt(Program->block_count * 4) - 1);
	// // printf("\e[1;34moutput count at exit: %zu\n\e[0m", bcnt);
	// // printf("\e[1;34m\nboard at exit(size %zu):\n\n\e[0m", Program->board->w);
	// // printf("board: \n\n");
	///bf_print(Program->board);  /// TAMA PRINTTAA BOARDIN
	printf("\n");
	printf("output render: \n\n");
	while (i < size)
	{
		array[i] = ft_calloc(size + 1, sizeof(char));
		while (j < size)
		{
			array[i][j] = '.';
			j++;
		}
		array[i][size] = '\n';
		array[i][size + 1] = '\0';
		j = 0;
		i++;
	}
	i = 0;
	while (Program->output)
	{
		tmp = Program->output->content;
		render(tmp, array, c);
		Program->output = Program->output->next;
		c++;
	}
	i = 0;
	while (i < size)
	{
		ft_putstr(array[i]);
	 	i++;
	}
}
