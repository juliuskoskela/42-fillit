/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:16:05 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/25 15:38:14 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

static size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

uint64_t		b(char *str)
{
	size_t		i;
	size_t		size;
	uint64_t	nb;

	i = 0;
	nb = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		if (str[i] == '1')
			nb |= 1 << i;
		if (str[i] != '1' && str[i] != '0')
			return (0);
		i++;
	}
	return (nb);
}
