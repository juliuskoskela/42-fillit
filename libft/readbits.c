/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readbits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 14:42:11 by esukava           #+#    #+#             */
/*   Updated: 2020/09/24 01:52:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint64_t		readbits(char *str, char c, size_t size)
{
	size_t		i;
	uint64_t	nb;

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
