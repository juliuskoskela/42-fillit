/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 17:03:22 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/24 01:49:12 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				bf_cmp(t_field **f1, t_field **f2)
{
	size_t		i;

	i = 0;
	if (!(*f1) || !(*f2))
		return (-1);
	while (i < 4)
	{
		if ((*f1)->row[i] != (*f2)->row[i])
			return (0);
		i++;
	}
	return (1);
}
