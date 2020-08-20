/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 09:24:53 by jkoskela          #+#    #+#             */
/*   Updated: 2020/07/01 02:07:56 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *h, const char *n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (h[0] == '\0' && n[0] == '\0')
		return ((char *)h);
	while (h[i] != '\0')
	{
		j = 0;
		while (n[j] != '\0' && h[i + j] == n[j])
			j++;
		if (n[j] == '\0')
			return ((char *)h + i);
		i++;
	}
	return (NULL);
}
