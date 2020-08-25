/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esukava <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:17:32 by esukava           #+#    #+#             */
/*   Updated: 2020/08/25 19:18:24 by esukava          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"
#include "../libft/libft.h"

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
