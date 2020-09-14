/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitoa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:06:14 by jkoskela          #+#    #+#             */
/*   Updated: 2020/09/14 16:09:52 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitlib.h"

char		*bitoa(uint64_t nb, size_t len)
{
	size_t		i;
	char		*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
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
