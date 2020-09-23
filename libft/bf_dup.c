/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 01:08:28 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 01:49:22 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_field		*bf_dup(t_field *src)
{
	t_field		*dest;
	size_t		i;

	i = 0;
	dest = bf_new(src->w, src->h);
	while (i < src->h)
	{
		dest->row[i] = src->row[i];
		i++;
	}
	return (dest);
}
