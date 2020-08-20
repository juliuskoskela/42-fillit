/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 23:04:12 by jkoskela          #+#    #+#             */
/*   Updated: 2020/07/01 00:12:33 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	n;
	char			*d;

	n = 0;
	d = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (d == NULL)
		return (NULL);
	while (s[n] != '\0')
	{
		d[n] = f(n, s[n]);
		n++;
	}
	d[n] = '\0';
	return (d);
}
