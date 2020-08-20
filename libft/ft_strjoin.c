/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 00:10:28 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/15 23:40:18 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		d = ft_strdup(s2);
	if (!s2)
		d = ft_strdup(s1);
	if (s1 && s2)
	{
		d = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		d = ft_strcpy(d, s1);
		d = ft_strcat(d, (char *)s2);
	}
	return (d);
}
