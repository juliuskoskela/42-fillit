/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:19:00 by jkoskela          #+#    #+#             */
/*   Updated: 2020/08/18 14:19:31 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcsub(char *s, char c)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	size_t	len;

	i = ft_lentoc(s, c) + 1;
	j = 0;
	len = ft_strlen(s) - i;
	tmp = ft_strnew(len + 1);
	while (s[i])
		tmp[j++] = s[i++];
	tmp[j] = '\0';
	return (tmp);
}
